// アプリ雛形
// 
// VisualStudioでもコンパイルできるようにするため
// ソースコードをUTF-8(BOM付き)で用意:D
//

// Frameworkの全てをインクルード
#include "lib/framework.hpp"

//Texture Balloon("res/キャラクター素材/Balloon.png");
//Texture Katikaku_1P("res/キャラクター素材/katikaku.png");
//Texture Katikaku_2P("res/キャラクター素材/secondplayer_katikaku.png");
//Texture Makekaku_1P("res/キャラクター素材/makekaku.png");
//Texture Makekaku_2P("res/キャラクター素材/secondplayer_makekaku.png");
//Texture Normal_1P("res/キャラクター素材/Normal.png");
//Texture Normal_2P("res/キャラクター素材/secondplayer_Normal.png");
//Texture Pleasure_1P("res/キャラクター素材/Pleasure.png");
//Texture Pleasure_2P("res/キャラクター素材/secondplayer_Pleasure.png");
//Texture Surprise_1P("res/キャラクター素材/Surprise.png");
//Texture Surprise_2P("res/キャラクター素材/secondplayer_Surprise.png");

// アプリのウインドウサイズ
enum Window {
	WIDTH = 1000,
	HEIGHT = 1000
};

enum Map{
	MAP_WIDTH = 8,
	MAP_HEIGHT=8
};
int map[MAP_HEIGHT][MAP_WIDTH] = {
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
};

// 
// メインプログラム
// 
int main() {
		// アプリウインドウを生成
		// GLFWとOpenGLの初期化
		// TIPS:色々な型が依存しているので、最初に生成する事
		AppEnv env(Window::WIDTH, Window::HEIGHT, false, true);

		while (env.isOpen()) {
			// 開始
			env.begin();

			for (int iy = 0; iy < MAP_HEIGHT; iy++){
				for (int ix = 0; ix < MAP_WIDTH; ix++)
				{
					drawBox(-500 + ix * 75, -300 + iy * 75, 75, 75, 1, Color::white);
				}
			}

			//自分
			drawFillBox(-500, -500, 800, 200, Color::white);
			//顔
			drawFillBox(300, -500, 200, 200, Color::cyan);

			//相手
			drawFillBox(-300, 300, 800, 200, Color::white);
			//顔
			drawFillBox(-500, 300, 200, 200, Color::magenta);

			//メニュー
			drawFillBox(100, -300, 400, 600, Color::yellow);



			// 終了
			env.end();
		}
	}
