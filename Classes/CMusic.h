﻿#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

class CMusic : public cocos2d::Node
{
protected:
	// tên file.mp3
	std::string _fileName;
	// số lượng nhịp trên 1 phút của bài hát
	float _bpm;
	// số frame trên giây
	float _fps;
	// frame hiện tại trong 1 bài nhạc
	int _frameCurrent;
	// số phách trong 1 nhịp
	int _measures;
	// phách hiện tại. bắt đầu từ 0
	int _measureCurrent;
	// nhịp hiện tại. bắt đầu từ 0
	int _beatCurrent;
	// khoang cach xuat hien cua Enemy so voi Hero. Khoang cach cang lon toc do quai di chuyen cang nhanh
	int _distance = 2000;
	// độ trễ của nốt đầu tiên suất hiện. Đơn vị là beat. Bắt buột > 1
	int _beatDelay = 4;

	// mảng đánh dấu
	std::map < int, std::vector<int> > _notesChanges;

	// các biến hỗ trợ tính toán

	// beat cuối cùng bị thay đổi
	int lastChangeFromBeat = -1;

	// số frame trên 1 phách; f = (_fps * 60) / (_bpm*_measures)
	float f;
	// đếm số frame trong 1 phách
	int count;

public:
	// phát nhạc
	void playMusic();

	// reset
	void resetMusic();

	// có đánh phách hay không
	int hasNote();
	// chưa nghĩ ra thuật toán
	bool hasNote(int deltaFrame);

	// đánh dấu các mốc thay đổi việc đánh phách. số lượng biến trong va_list = _measures
	void addChange(int beatStart, ...);

	// định nghĩa cho nhạc
	virtual bool init();

	// update thuộc tính theo từng frame
	void update(float dt);

	/* ví dụ test: bpm = 120, measures = 4, f = 7.5
	beat 0: khoảng nghỉ
			- note: 0
	beat 2: bắt đầu phát nhạc
			- note: measume 1
	beat 5: cao trào
			- note: measume 1,2,4
	beat 25: khoảng nghỉ
			- note: 0
	*/

	// getter
	std::string getFileName();
	float getBpm();
	float getFps();
	int getFrameCurrent();
	int getMeasures();
	int getMeasureCurrent();
	int getBeatCurrent();
	void logNotesChanges();
	float getFramePerBeat();
	int getDistance();
	int getBeatDelay();

};

