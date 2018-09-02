#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define IMG_NUM 10
#define IMG_SET_NUM 4

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void imageLoad(int nParam); //画像の読み込み（引数はセット番号）

		void method1(int imgNo);
		void method2(int imgNo);
		void method3(int imgNo);
		void method4(int imgNo, int mode);
		void method5(int imgNo, int mode);
		void method6(int imgNo,int mode);
		void AllReflesh();		//すべての画像を元に戻す
		void Reflesh(int imgNo);//画像を元に戻す
		bool m_bMethod3on;		//method3がonかoffか
		
		bool m_bMethod4on;		//method4がonかoffか
		int m_nMethod4Mode;		//method4のモード
		int m_randWs_method4;
		int m_randWe_method4;

		bool m_bMethod5on;		//method5がonかoffか
		int m_nMethod5Mode;		//method5のモード
		int m_randHs_method5;
		int m_randHe_method5;

		ofImage			img[IMG_NUM];	//画像の格納変数
		ofxCvColorImage imgCv[IMG_NUM]; //画像の格納変数
		int m_nTime;		//画像切り替え間隔時間
		int m_nViewNo;		//表示画像番号
		int m_nCurX;		//マウスカーソル位置X
		int m_nCurY;		//マウスカーソル位置Y
		bool m_bStop;		//写真切り替えのON/OFF
		int m_nImageSetNo;	//写真のセット番号
};
