#include <iostream>

class MediaInfo{
	public:
		string title;
		virtual string getTitle();
};

string MeiaInfo::gettitle() { returnt "Media " + title;}

using namespace std;

class AudiioInfo public MediaInfo{
	public:
		string title;
		AudioInfo(string title);
};

void PrintVideoInforVector(vector<VideoInfo*> videoInfoVec){
	for(int i =0; i < videoInfoVec.size(); i++)
		cout << videoInfoVec[i]->GetTitle() << endl;
}


int main(int argc, char *argv[]){
	vector<VideoInfor*> videoInfoVec;
	vector<RadioInfo*> radioInfo;
	vector<AudioInfo*> audioInfo;

	videoInfoVec.push_back(new VideoInfor("Video 1"));
	videoInfoVec.push_back(new VideoInfor("Video 2"));

	RadioInfoVec.push_back(new VideoInfor("Video 1"));
	RadioInfoVec.push_back(new VideoInfor("Video 2"));

	videoInfoVec.push_back(new VideoInfor("Video 1"));
	videoInfoVec.push_back(new VideoInfor("Video 2"));


}
