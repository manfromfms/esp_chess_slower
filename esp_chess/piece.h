#pragma once

#include <iostream>
#include <string>

namespace chs {
	class piece
	{
	public:
		bool isNull = true;

		bool isWhite = true;

		bool isPawn = false;
		bool isBishop = false;
		bool isKnight = false;
		bool isRook = false;
		bool isQueen = false;
		bool isKing = false;

		char symbol = '-';

		piece() {
			isNull = true;
		}

		piece(char p) {
			symbol = p;

			if (p == 'p' || p == 'P') {
				isWhite = p == 'P';
				isPawn = true;
				isNull = false;

				return;
			}

			if (p == 'b' || p == 'B') {
				isWhite = p == 'B';
				isBishop = true;
				isNull = false;

				return;
			}

			if (p == 'n' || p == 'N') {
				isWhite = p == 'N';
				isKnight = true;
				isNull = false;

				return;
			}

			if (p == 'r' || p == 'R') {
				isWhite = p == 'R';
				isRook = true;
				isNull = false;

				return;
			}

			if (p == 'q' || p == 'Q') {
				isWhite = p == 'Q';
				isQueen = true;
				isNull = false;

				return;
			}

			if (p == 'k' || p == 'K') {
				isWhite = p == 'K';
				isKing = true;
				isNull = false;

				return;
			}

			symbol = '-';
			isNull = true;
		}
	};


};