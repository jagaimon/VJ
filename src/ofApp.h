#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#define IMG_NUM 10

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
		
		void method1(int imgNo);
		void method2(int imgNo);
		void method3(int imgNo);
		void method4(int imgNo, int mode);
		void method5(int imgNo,int mode);
		void AllReflesh();
		void Reflesh(int imgNo);
		bool m_bMethod3on;
		bool m_bMethod4on;
		bool m_bMethod5on;
		int m_nMethod4Mode;
		int m_nMethod5Mode;

		ofImage			img[IMG_NUM];
		ofxCvColorImage imgCv[IMG_NUM];
		int m_nTime;
		int m_nViewNo;
		int m_nCurX;
		int m_nCurY;
		bool m_bStop;
		int m_randWs_method4;
		int m_randWe_method4;
		int m_randHs_method5;
		int m_randHe_method5;
};
