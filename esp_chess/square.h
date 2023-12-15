#pragma once

#include "piece.h"

namespace chs {
	class square
	{
	public:
		int row = 0;
		int col = 0;

		chs::piece piece;

		square() {

		}

		square(int c, int r) {
			row = r;
			col = c;
		}

		square(int c, int r, char p) {
			row = r;
			col = c;

			piece = chs::piece(p);
		}

		square(int c, int r, chs::piece piece) {
			row = r;
			col = c;

			this->piece = piece;
		}
	};

};