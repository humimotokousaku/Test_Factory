#pragma once

namespace ActionConfig {
	namespace Mask {
		// 移動状態
		namespace Movement {
			// メイン状態
			namespace MainAction {
				// 移動
				inline const unsigned int move = 0b01;

				// メイン状態すべて
				inline const unsigned int all = move;
			}
			// サブ状態
			namespace SubAction {
				// ジャンプ
				inline const unsigned int jump = 0b01 << 1;
				// スライディング
				inline const unsigned int sliding = 0b01 << 2;
				// 回避
				inline const unsigned int evasion = 0b01 << 3;

				// サブ状態すべて
				inline const unsigned int all = jump | sliding | evasion;
			}

			// 移動状態すべて
			inline const unsigned int all = MainAction::all | SubAction::all;
		}
		// 武器状態
		namespace Weapon {
			// メイン状態
			namespace MainAction {
				// 射撃
				inline const unsigned int shot = 0b01 << 4;
				// リロード
				inline const unsigned int reloading = 0b01 << 5;

				// メイン状態すべて
				inline const unsigned int all = shot | reloading;
			}
			// サブ状態
			namespace SubAction {
				// エイム
				inline const unsigned int ads = 0b01 << 6;

				// サブ状態すべて
				inline const unsigned int all = ads;
			}

			// 武器状態すべて
			inline const unsigned int all = MainAction::all | SubAction::all;
		}

		// 全てのマスク
		inline const unsigned int all = Movement::all | Weapon::all;
	}
}