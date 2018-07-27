#include "ofApp.h"

#include <iostream>
#include <time.h>   // time関数
#include <stdlib.h> // rand, srand関数
//--------------------------------------------------------------
void ofApp::setup() {
	img[0].load("images/1_0.JPG");
	img[1].load("images/1_1.JPG");
	img[2].load("images/1_2.JPG");
	img[3].load("images/1_3.JPG");
	img[4].load("images/1_4.JPG");
	img[5].load("images/1_5.JPG");
	img[6].load("images/1_6.JPG");
	img[7].load("images/1_7.JPG");
	img[8].load("images/1_8.JPG");
	img[9].load("images/1_9.JPG");
	for (int i = 0;i < IMG_NUM;i++)
	{
		imgCv[i].allocate(img[i].getWidth(), img[i].getHeight());
		imgCv[i].setFromPixels(img[i].getPixelsRef());
	}
	m_nTime = 0;
	m_bStop = false;
	m_bMethod3on = false;
	m_bMethod4on = false;
	m_bMethod5on = false;
	m_nViewNo = 0;
	m_nCurX = 0;
	m_nCurY = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	Sleep(m_nTime);
	if (m_bStop) {
		imgCv[m_nViewNo].draw(0, 0, 1000, 500);
	}
	else {
		m_nViewNo = rand() % IMG_NUM;
		imgCv[m_nViewNo].draw(0, 0, 1000, 500);
	}
	if (m_bMethod3on) {
		method3(m_nViewNo);
	}
	if (m_bMethod4on) {
		method4(m_nViewNo, m_nMethod4Mode);
	}
	if (m_bMethod5on) {
		method5(m_nViewNo, m_nMethod5Mode);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case OF_KEY_RETURN:
			break;
		case 49://1
			method1(m_nViewNo);
			cout << "method1" << endl;
			break;
		case 50://2
			method2(m_nViewNo);
			cout << "method2" << endl;
			break;
		case 51://3
			if (m_bMethod3on) {
				m_bMethod3on = false;
				cout << "method3 OFF" << endl;
			}
			else {
				m_bMethod3on = true;
				cout << "method3 ON" << endl;
			}
			break;
		case 52://4
		case 114://R
		case 102://F
			if (key == 52)
			{
				m_nMethod4Mode = 0;
			}
			else if (key == 114)
			{
				m_nMethod4Mode = 1;
			}
			else if (key == 102)
			{
				//m_nMethod4Mode = 2;
			}

			if (m_bMethod4on) {
				m_bMethod4on = false;
				cout << "method4 OFF" << endl;
			}
			else {
				m_bMethod4on = true;
				cout << "method4 ON, Mode:"  << m_nMethod4Mode << endl;
			}
			break;
		case 53://5
		case 116://T
		case 103://G
			if (key == 53)
			{
				m_nMethod5Mode = 0;
			}
			else if (key == 116)
			{
				m_nMethod5Mode = 1;
			}
			else if (key == 103)
			{
				m_nMethod5Mode = 2;
			}
			if (m_bMethod5on) {
				m_bMethod5on = false;
				cout << "method5 OFF" << endl;
			}
			else {
				m_bMethod5on = true;
				cout << "method5 ON, Mode:" << m_nMethod5Mode << endl;
			}
			break;
		case 54://6
			break;
		case 97://a
			AllReflesh();
			break;
		case 99://c
			Reflesh(m_nViewNo);
			break;
		case 115://s
			if (m_bStop) {
				m_bStop = false;
				cout << "start" << endl;
			}
			else {
				m_bStop = true;
				cout << "stop" << endl;
			}
			break;
		case OF_KEY_UP:
			m_nViewNo++;
			if (m_nViewNo >= IMG_NUM) {
				m_nViewNo = 0;
			}
			break;
		case OF_KEY_DOWN:
			m_nViewNo--;
			if (m_nViewNo < 0) {
				m_nViewNo = IMG_NUM-1;
			}
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	m_nTime = y/5;
	m_nCurX = x;
	m_nCurY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::AllReflesh() {//初期状態に戻す
	for (int i = 0;i < IMG_NUM;i++)
	{
		Reflesh(i);
	}
}

//--------------------------------------------------------------
void ofApp::Reflesh(int imgNo) {//初期状態に戻す
	imgCv[imgNo].setFromPixels(img[imgNo].getPixelsRef()); 
}

//--------------------------------------------------------------
void ofApp::method1(int imgNo) {//ストライプ状に色を変化
	Reflesh(imgNo);
	unsigned char *img1Data = imgCv[imgNo].getPixels().getData();
	int w = img[imgNo].getWidth();
	int i, j;
	bool gray = false;
	uchar p[3];
	uchar p2[3];
	for (i = 0; i < img[imgNo].getHeight(); i++) {

		for (j = 0; j < img[imgNo].getWidth(); j++) {
			unsigned int    now = (unsigned int)time(0);
			srand(now);

			int ran1;
			int ran2;
			int ran3;
			p[0] = img1Data[i * 3 * w + j * 3];
			p[1] = img1Data[i * 3 * w + j * 3 + 1];
			p[2] = img1Data[i * 3 * w + j * 3 + 2];

			if (j % ((int)img[imgNo].getHeight() / 50) == 0) {
				if (gray)	gray = false;
				else		gray = true;
			}
			if (gray) {
				img1Data[i * 3 * w + j * 3] = 180 - p[0];
				img1Data[i * 3 * w + j * 3 + 1] = 180 - p[1];
				img1Data[i * 3 * w + j * 3 + 2] = 180 - p[2];
			}

			else if (rand() % 10 == 0) {
				ran1 = rand() % 180;
				if (rand() % 2 == 1) {
					ran1 *= -1;
				}
				ran2 = rand() % 180;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				ran3 = rand() % 180;
				if (rand() % 2 == 1) {
					ran3 *= -1;
				}
				p2[0] = ran1;
				p2[1] = ran2;
				p2[2] = ran3;
				img1Data[i * 3 * w + j * 3] = p[1] + p2[0];
				img1Data[i * 3 * w + j * 3 + 1] = p[0] + p2[1];
				img1Data[i * 3 * w + j * 3 + 2] = p[2] + p2[2];
			}
			else {
				ran1 = rand() % 20;
				if (rand() % 2 == 1) {
					ran1 *= -1;
				}
				ran2 = rand() % 20;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				ran3 = rand() % 20;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				p2[0] = ran1;
				p2[1] = ran2;
				p2[2] = ran3;
				img1Data[i * 3 * w + j * 3] = p[1] + p2[0];
				img1Data[i * 3 * w + j * 3 + 1] = p[0] + p2[1];
				img1Data[i * 3 * w + j * 3 + 2] = p[2] + p2[2];
			}
		}
	}
	imgCv[imgNo].setFromPixels(imgCv[imgNo].getPixels());
}

//--------------------------------------------------------------
void ofApp::method2(int imgNo) {
	unsigned char *img1Data = imgCv[imgNo].getPixels().getData();
	int w = img[imgNo].getWidth();
	bool gray = false;
	uchar p[3];
	if (m_nCurY >= img[imgNo].getHeight()) {
		m_nCurY = img[imgNo].getHeight() - 1;
	}
	if (m_nCurX >= img[imgNo].getWidth()) {
		m_nCurX = img[imgNo].getWidth() - 1;
	}

	p[0] = img1Data[m_nCurY * 3 * w + m_nCurX * 3];
	p[1] = img1Data[m_nCurY * 3 * w + m_nCurX * 3 + 1];
	p[2] = img1Data[m_nCurY * 3 * w + m_nCurX * 3 + 2];

	for (int i = m_nCurY - 50;i < m_nCurY;i++) {
		if (i < 0)continue;
		for (int j = m_nCurX - 50;j < m_nCurX;j++) {
			if (j < 0)continue;
			img1Data[i * 3 * w + j * 3] = 180 - p[0];
			img1Data[i * 3 * w + j * 3 + 1] = 180 - p[1];
			img1Data[i * 3 * w + j * 3 + 2] = 180 - p[2];
		}
	}

	imgCv[imgNo].setFromPixels(imgCv[imgNo].getPixels());
}

//--------------------------------------------------------------
void ofApp::method3(int imgNo) {//全体的にノイズ
	//int changeNo = rand() % IMG_NUM;
	//if (imgNo == changeNo) return;
	unsigned char *img1Data = imgCv[imgNo].getPixels().getData();
	//unsigned char *imgRData = imgCv[changeNo].getPixels().getData();
	int i,j;
	uchar p[3];
	uchar p2[3];
	//uchar p[90000][3];
	//int nRandX, nRandY;
	int ran1, ran2, ran3;
	int w = img[imgNo].getWidth();

	for (i = 0; i < img[imgNo].getHeight(); i++) {
		for (j = 0; j < img[imgNo].getWidth(); j++) {
			if (rand() % 7 == 0)
			{

				p[0] = img1Data[i * 3 * w + j * 3];
				p[1] = img1Data[i * 3 * w + j * 3 + 1];
				p[2] = img1Data[i * 3 * w + j * 3 + 2];

				ran1 = rand() % 180;
				if (rand() % 2 == 1) {
					ran1 *= -1;
				}
				ran2 = rand() % 180;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				ran3 = rand() % 180;
				if (rand() % 2 == 1) {
					ran3 *= -1;
				}
				p[0] = ran1;
				p[1] = ran2;
				p[2] = ran3;
				img1Data[i * 3 * w + j * 3] = p[1] + p2[0];
				img1Data[i * 3 * w + j * 3 + 1] = p[0] + p2[1];
				img1Data[i * 3 * w + j * 3 + 2] = p[2] + p2[2];
			}
		}
	}

	//コピー元の画像からデータを取得
	//w = img[changeNo].getWidth();
	//nRandX = img[changeNo].getWidth();
	//nRandY = img[changeNo].getHeight();
	//int count = 0;
	//for (int i = 0; i < nRandY; i++) {
	//	for (int j = 0; j < nRandX; j++) {

	//		if (rand()%10 == 0) {
	//			if (count < 90000) {
	//				p[count][0] = imgRData[i * 3 * w + j * 3];
	//				p[count][1] = imgRData[i * 3 * w + j * 3 + 1];
	//				p[count][2] = imgRData[i * 3 * w + j * 3 + 2];
	//			}
	//			count++;
	//		}
	//	}
	//}

	////コピーしたデータを移す
	//w = img[imgNo].getWidth();
	//nRandX = img[imgNo].getWidth();
	//nRandY = img[imgNo].getHeight();
	//for (int i = 0; i < nRandY; i++) {
	//	for (int j = 0; j < nRandX; j++) {

	//		if (rand() % 7 == 0) {
	//			img1Data[i * 3 * w + j * 3] = p[rand() % (int)count][0];
	//			img1Data[i * 3 * w + j * 3 + 1] = p[rand() % (int) count][1];
	//			img1Data[i * 3 * w + j * 3 + 2] = p[rand() % (int) count][2];
	//		}
	//	}
	//}

	imgCv[imgNo].setFromPixels(imgCv[imgNo].getPixels());
}

//--------------------------------------------------------------
void ofApp::method4(int imgNo, int mode) {//縦ノイズ
	unsigned char *img1Data = imgCv[imgNo].getPixels().getData();
	int w = img[imgNo].getWidth();
	int i, j;
	bool gray = false;
	uchar p[3];
	uchar p2[3];
	int ran1, ran2, ran3;
	int randWs_method4 = rand() % (int)img[imgNo].getWidth();
	int randWe_method4 = rand() % (int)img[imgNo].getWidth()/8;

	if (m_randWs_method4 == randWs_method4 && m_randWe_method4 == randWe_method4)
	{//randの値が前と同じだったら実行しない
		return;
	}
	m_randWs_method4 = randWs_method4;
	m_randWe_method4 = randWe_method4;

	unsigned int    now = (unsigned int)time(0);
	srand(now);

	for (i = 0; i < img[imgNo].getHeight(); i++) {
		int count = 0;
		for (j = m_randWs_method4; j < img[imgNo].getWidth(); j++) {
			if (count > m_randWe_method4) {
				break;
			}
			count++;
			p[0] = img1Data[i * 3 * w + j * 3];
			p[1] = img1Data[i * 3 * w + j * 3 + 1];
			p[2] = img1Data[i * 3 * w + j * 3 + 2];

			if (mode ==1) {//色反転
				img1Data[i * 3 * w + j * 3] = 180 - p[0];
				img1Data[i * 3 * w + j * 3 + 1] = 180 - p[1];
				img1Data[i * 3 * w + j * 3 + 2] = 180 - p[2];
			}
			else if (mode == 0) {//ただのノイズ
				ran1 = rand() % 180;
				if (rand() % 2 == 1) {
					ran1 *= -1;
				}
				ran2 = rand() % 180;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				ran3 = rand() % 180;
				if (rand() % 2 == 1) {
					ran3 *= -1;
				}
				p2[0] = ran1;
				p2[1] = ran2;
				p2[2] = ran3;
				img1Data[i * 3 * w + j * 3] = p[1] + p2[0];
				img1Data[i * 3 * w + j * 3 + 1] = p[0] + p2[1];
				img1Data[i * 3 * w + j * 3 + 2] = p[2] + p2[2];
			}
		}
	}
	imgCv[imgNo].setFromPixels(imgCv[imgNo].getPixels());
}

//--------------------------------------------------------------
void ofApp::method5(int imgNo, int mode) {//横ノイズ
	unsigned char *img1Data = imgCv[imgNo].getPixels().getData();
	int w = img[imgNo].getWidth();
	int i, j;
	bool gray = false;
	uchar p[3];
	uchar p2[3];
	int ran1, ran2, ran3;
	int randHs_method5 = rand() % (int)img[imgNo].getWidth();
	int randHe_method5 = rand() % (int)img[imgNo].getWidth() / 8;

	if (m_randHs_method5 == randHs_method5 && m_randHe_method5 == randHe_method5)
	{//randの値が前と同じだったら実行しない
		return;
	}
	m_randHs_method5 = randHs_method5;
	m_randHe_method5 = randHe_method5;

	unsigned int    now = (unsigned int)time(0);
	srand(now);
	int count = 0;
	//cout << m_randHs_method5 << " " << m_randHe_method5 << endl;

	for (i = m_randHs_method5; i < img[imgNo].getHeight(); i++) {
		if (count > m_randHe_method5) {
			break;
		}
		count++;
		for (j = 0; j < img[imgNo].getWidth(); j++) {
			p[0] = img1Data[i * 3 * w + j * 3];
			p[1] = img1Data[i * 3 * w + j * 3 + 1];
			p[2] = img1Data[i * 3 * w + j * 3 + 2];

			if (mode ==1) {

				img1Data[i * 3 * w + j * 3] = 180 - p[0];
				img1Data[i * 3 * w + j * 3 + 1] = 180 - p[1];
				img1Data[i * 3 * w + j * 3 + 2] = 180 - p[2];
			}
			else if (mode == 0)
			{
				ran1 = rand() % 180;
				if (rand() % 2 == 1) {
					ran1 *= -1;
				}
				ran2 = rand() % 180;
				if (rand() % 2 == 1) {
					ran2 *= -1;
				}
				ran3 = rand() % 180;
				if (rand() % 2 == 1) {
					ran3 *= -1;
				}
				p2[0] = ran1;
				p2[1] = ran2;
				p2[2] = ran3;
				img1Data[i * 3 * w + j * 3] = p[1] + p2[0];
				img1Data[i * 3 * w + j * 3 + 1] = p[0] + p2[1];
				img1Data[i * 3 * w + j * 3 + 2] = p[2] + p2[2];
			}
			else if (mode == 2)
			{
				if (j + randHe_method5 >= img[imgNo].getWidth()) {
					continue;
				}
				img1Data[i * 3 * w + j * 3] = img1Data[i * 3 * w + (j+ randHe_method5) * 3];
				img1Data[i * 3 * w + j * 3 + 1] = img1Data[i * 3 * w + (j + randHe_method5) * 3 + 1];
				img1Data[i * 3 * w + j * 3 + 2] = img1Data[i * 3 * w + (j + randHe_method5) * 3 + 2];
			}
		}
	}
	imgCv[imgNo].setFromPixels(imgCv[imgNo].getPixels());
}