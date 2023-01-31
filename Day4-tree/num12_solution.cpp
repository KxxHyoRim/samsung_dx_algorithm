#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
using namespace std;
//todo I/O관련 코드 지우기!!

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.
/*
int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}
*/

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}


struct Node {
    int idx;
    string data;
    list<Node> child;
};

vector<Node> nodeList{2000};

void init(int n) {
    nodeList.clear();
    nodeList.resize(n);
    nodeList[0] = Node{0, "/"};
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    string dir = path;
    string child_dir;
    vector<string> dirList = split(dir,'/');
    // "/" -> dirList[0] = ""
    // "/aa/" -> dirList[0] = "", dirList[1] = "aa"
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {

}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {

}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {

}

int cmd_find(char path[PATH_MAXLEN + 1]) {

    return 0;
}