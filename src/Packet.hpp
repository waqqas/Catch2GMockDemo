#pragma once

#include <string>
#include <array>

namespace data
{
class Packet
{
 public:
	void reset(void)
	{
		packet_size = 0;
		packet_seq_no = 0;
		packet_loss_sequence_number = 0;
		feed_type = "X";		// invalid type
	}

	std::array<unsigned char, 1500> packet;
	size_t packet_size;											// size of packet in bytes
	uint32_t packet_seq_no;										// current packet sequence number
	uint32_t packet_loss_sequence_number;					// last sequence number received after loss in a sequence (0 if no loss)
	std::string feed_type;												// I=incremental N=security def S=snapshot feed
};
} // namespace bts
