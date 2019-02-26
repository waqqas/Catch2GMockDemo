
#include "MessageQueue.hpp"
#include "Packet.hpp"

#include <spdlog/spdlog.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <catch2/catch.hpp>

#include <thread>
#include <atomic>

int run_tests(int argc, char *argv[])
{
  ::testing::GTEST_FLAG(throw_on_failure) = true;
  ::testing::InitGoogleMock(&argc, argv);

  return Catch::Session().run(argc, argv);
}

int run_app(int argc, char *argv[])
{
  using Queue = utility::MessageQueue<data::Packet>;

  std::atomic<bool> continue_producing = true;
  Queue queue(2048);

  std::thread producer([&]() {
    uint32_t input = 1;
    data::Packet *packet;

    while (continue_producing)
    {
      // usleep(0);
      if (queue.get_empty_packet(packet))
      {

        packet->packet_seq_no = input++;
        packet->feed_type = "I";

        queue.put_filled_packet(packet);
      }
    }
  });

  usleep(1000);

  std::thread consumer([&]() {
    uint32_t previous = 0;
    data::Packet *packet;

    while (true)
    {
      usleep(0);
      if (queue.get_filled_packet(packet))
      {

        if (previous + 1 != packet->packet_seq_no)
        {
          std::cout << "previous: " << previous << " current: " << packet->packet_seq_no << std::endl;
          break;
        }

        if (packet->packet_seq_no >= 100000)
        {
          break;
        }

        previous = packet->packet_seq_no;

        queue.put_empty_packet(packet);
      }
    }

    std::cout << "final output: " << previous << std::endl;
    continue_producing.store(false);
  });

  producer.join();
  consumer.join();

  return 0;
}

int main(int argc, char *argv[])
{
  int result = 0;

  if (argc >= 2 && strcmp(argv[1], "test") == 0)
  {
    result = run_tests(--argc, &argv[1]);
  }
  else
  {
    result = run_app(argc, argv);
  }

  return result;
}