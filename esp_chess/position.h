#pragma once

#include <vector>
#include "piece.h"
#include "square.h"
#include "move.h"

namespace chs {

	class position
	{
	public:
		std::vector<chs::square> field;
		bool isWhitesTurn = true;

		std::string toString() {
			std::string result;

			for (auto& p : field) {
				result += p.piece.symbol;

				if (p.col == 7) result += "\n";
			}

			return result;
		}

		std::vector<chs::move> generateMoves() {
			std::vector<chs::move> moves;
			bool isCapture = false;

			for (auto& square : this->field) {
				if (square.piece.isNull || square.piece.isWhite != this->isWhitesTurn) continue;

				std::vector<chs::move> temp;

				if (square.piece.isKnight) temp = this->generateKnight(square);

				if (temp.size() == 0) continue;

				if (moves.size() == 0) {
					moves = temp;
					continue;
				}

				if (temp[0].isCaputre) {
					if (!isCapture) {
						isCapture = true;
						moves = temp;
					}
				}
				else {
					if(!isCapture) moves.insert(moves.end(), temp.begin(), temp.end());
				}
			}

			return moves;
		}

		std::vector<chs::move> generateKnight(chs::square square) {
			int dx[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };
			int dy[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };

			std::vector<chs::move> result;
			bool isCapture = false;

			for (int i = 0; i < 8; i++) {
				int nx = square.col + dx[i];
				int ny = square.row + dy[i];

				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

				if (!field[nx + ny * 8].piece.isNull && field[nx + ny * 8].piece.isWhite == square.piece.isWhite) continue;

				if (field[nx + ny * 8].piece.isNull) {
					if (!isCapture) {
						result.push_back(chs::move(square, chs::square(nx, ny, square.piece)));
					}
				}
				else {
					if (!isCapture) {
						isCapture = true;
						result.clear();
					}

					result.push_back(chs::move(true, square, chs::square(nx, ny, square.piece)));
				}

			}

			return result;
		}
	};

	static chs::position importPosition(std::string fen) {
		chs::position result;

		int counter = 0;
		int i = 0;
		for (; i < fen.size(); i++) {
			char p = fen[i];

			if (int(p) >= 48 && int(p) <= 57) {
				int num = int(p) - 48;

				while (num--) {
					result.field.push_back(chs::square(counter % 8, 7 - counter / 8));
					counter++;
				}
			}
			else {
				if (p == ' ') break;

				if (p == '/') continue;

				result.field.push_back(chs::square(counter % 8, 7 - counter / 8, p));

				counter++;
			}
		}

		i += 1;

		result.isWhitesTurn = fen[i] == 'w';

		return result;
	}
};