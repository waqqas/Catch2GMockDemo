#pragma once

#include "spdlog/spdlog.h"

#include <vector>
#include <atomic>
#include <sstream>

namespace utility
{
template <class T>
class MessageQueue
{
   typedef uint32_t counter;

 public:
   MessageQueue(size_t num_elements) : read_index_(0), write_index_(0), data_(num_elements), 
   mask_(num_elements)
   {
      T empty;
      for(std::size_t count = 0; count < data_.size(); count++){
         data_[count] = empty;
      }
   }

   inline bool is_empty()
   {
      return (read_index_.load(std::memory_order_relaxed) == write_index_.load(std::memory_order_relaxed));
   }

   inline bool is_full()
   {
      return ( 1 == ((read_index_.load(std::memory_order_relaxed) - write_index_.load(std::memory_order_relaxed)) % mask_));
   }

   inline bool get_empty_packet(T *&element)
   {
      if(!is_full()){
         element = &data_[write_index_.load() % mask_];
         std::atomic_thread_fence(std::memory_order_acquire);

         {
            std::stringstream stream;
            stream << std::hex << element;
            spdlog::info("Get-Empty at: {} seq-no: {}-{} {}", write_index_.load(), element->packet_seq_no, element->feed_type, stream.str());
         }

         return true;
      }
      return false;
   }

   inline bool mark_as_filled(T *element)
   {
      (void)element;

      {
         std::stringstream stream;
         stream << std::hex << element;

         spdlog::info("Mark-As-Filled at: {} seq-no: {}-{} {}", write_index_.load(), element->packet_seq_no, element->feed_type, stream.str());
      }   

      std::atomic_thread_fence(std::memory_order_release);
      write_index_.fetch_add(1, std::memory_order_relaxed);
      return true;
   }

   inline bool get_filled_packet(T *&element)
   {
      if(!is_empty()){
         std::atomic_thread_fence(std::memory_order_acquire);
         element = &data_[read_index_.load() % mask_];

         {
            std::stringstream stream;
            stream << std::hex << element;
            spdlog::info("Get-Filled at: {} seq-no: {}-{} {}", read_index_.load(), element->packet_seq_no, element->feed_type, stream.str());
         }

         return true;
      }
      return false;
   }

   inline bool mark_as_empty(T *element)
   {
      (void)element;

      {
         std::stringstream stream;
         stream << std::hex << element;

         spdlog::info("Mark-As-Empty at: {} seq-no: {}-{} {}", read_index_.load(), element->packet_seq_no, element->feed_type, stream.str());
      }  

      std::atomic_thread_fence(std::memory_order_release);
      read_index_.fetch_add(1, std::memory_order_relaxed);

      return true;
   }

 private:
   std::atomic<counter> read_index_;
   std::atomic<counter> write_index_;

   std::vector<T> data_;
   counter mask_;

};
} // namespace bts
