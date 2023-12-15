#pragma once

#include "position.h"

namespace chs {
	class Chess
	{
	public:
		chs::position position;

		Chess(std::string fen) {
			position = chs::importPosition(fen);
		}

		std::string displayMovesArray(std::vector<chs::move> moves) {
			std::string result = "Moves: ";

			for (auto move : moves) {
				result += move.toUCI() + " ";
			}

			return result;
		}
	};
};