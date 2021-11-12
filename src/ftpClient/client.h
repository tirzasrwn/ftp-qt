#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include <QString>

#include "infothread.h"

// const int PORT = 21;
const int BUFLEN = 1000;
const int DATABUFLEN = 1000;
const char *const DELIMITER = "\r\n";

class Client
{
private:
    int getStateCode();
    int getPortNum();
    int getFileSize(std::string fname);
    int listPwd();
    int intoPasv();
    int recvControl(int stateCode, std::string errorInfo = "0");
    int executeCmd(std::string cmd);
    void removeSpace(std::string &);

    sockaddr_in serverAddr;
    std::string ip_addr, username, password, INFO;
    uint16_t port;
    char *buf = new char[BUFLEN];
    char *databuf = new char[DATABUFLEN];
    int controlSocket;
    int16_t dataSocket;
    std::string recvInfo;
    std::string nextInfo; //JUNK

public:
    Client();
    ~Client();
    int connectServer();
    int disconnect();
    int changeDir(std::string tardir);
    int login(QString ip_addr, QString port, QString username, QString password);
    int downFile(std::string remoteName, std::string localDir);
    int upFile(std::string localName);
    int deleteFile(std::string fname);
    int deleteDir(std::string dname);
    int rename(std::string src, std::string dst);
    int mkDir(std::string name);

    InfoThread *infoThread;
    std::string pwd;
    std::vector<std::vector<std::string>> filelist;
};

#endif // CLIENT_H
