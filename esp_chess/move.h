#pragma once

#include "square.h"

namespace chs {
	class move
	{
	public:
		chs::square from;
		chs::square to;

		bool isCapture = false;

		move(chs::square f, chs::square t) {
			from = f;
			to = t;
		}

		move(bool isC, chs::square f, chs::square t) {
			from = f;
			to = t;

			isCapture = isC;
		}

		std::string toUCI() {
			std::string result;

			//std::cout << this->from.col << " " << this->from.row << " " << this->to.col << " " << this->to.row << " " << (isCaputre ? "Capture" : "Move") << std::endl;

			std::string columns = "abcdefgh";
			std::string rows = "12345678";

			result += columns[from.col];
			result += rows[from.row];

			result += columns[to.col];
			result += rows[to.row];

			return result;
		}
	};
};