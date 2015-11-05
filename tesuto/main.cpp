#include "player.h"
// アプリ雛形
// 
// VisualStudioでもコンパイルできるようにするため
// ソースコードをUTF-8(BOM付き)で用意:D
//

// Frameworkの全てをインクルード
#include "lib/framework.hpp"


// アプリのウインドウサイズ
enum Window {
  WIDTH  = 1000,
  HEIGHT = 1000
};


// 
// メインプログラム
// 
int main() {
  // アプリウインドウを生成
  // GLFWとOpenGLの初期化
  // TIPS:色々な型が依存しているので、最初に生成する事
  AppEnv env(Window::WIDTH, Window::HEIGHT,false,false);

  while (env.isOpen()) {
    // 開始
    env.begin();

	for (int iy = 0; iy < 8; iy++){
		for (int ix = 0; ix < 8; ix++)
		{
			drawBox(-500+ix*75, -300+iy*75, 75, 75, 1, Color::white);
		}
	}

	//自分
	drawFillBox(-500, -500,800, 200, Color::white);
	drawFillBox(300, -500, 200, 200, Color::cyan);

	////相手
	drawFillBox(-500, 300, 200, 1000, Color::magenta);
	drawFillBox(-300, 330, 800, 186, Color::white);
	
	//メニュー
	drawFillBox(100, -300, 400, 600, Color::yellow);
    


	// 終了
    env.end();
  }
}
