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
		
		void imageLoad(int nParam); //�摜�̓ǂݍ��݁i�����̓Z�b�g�ԍ��j

		void method1(int imgNo);
		void method2(int imgNo);
		void method3(int imgNo);
		void method4(int imgNo, int mode);
		void method5(int imgNo, int mode);
		void method6(int imgNo,int mode);
		void AllReflesh();		//���ׂẲ摜�����ɖ߂�
		void Reflesh(int imgNo);//�摜�����ɖ߂�
		bool m_bMethod3on;		//method3��on��off��
		
		bool m_bMethod4on;		//method4��on��off��
		int m_nMethod4Mode;		//method4�̃��[�h
		int m_randWs_method4;
		int m_randWe_method4;

		bool m_bMethod5on;		//method5��on��off��
		int m_nMethod5Mode;		//method5�̃��[�h
		int m_randHs_method5;
		int m_randHe_method5;

		ofImage			img[IMG_NUM];	//�摜�̊i�[�ϐ�
		ofxCvColorImage imgCv[IMG_NUM]; //�摜�̊i�[�ϐ�
		int m_nTime;		//�摜�؂�ւ��Ԋu����
		int m_nViewNo;		//�\���摜�ԍ�
		int m_nCurX;		//�}�E�X�J�[�\���ʒuX
		int m_nCurY;		//�}�E�X�J�[�\���ʒuY
		bool m_bStop;		//�ʐ^�؂�ւ���ON/OFF
		int m_nImageSetNo;	//�ʐ^�̃Z�b�g�ԍ�
};
