#include "aa_tree.h"

class TcpServer {
public:
  void run(AaTree * & tree, int port = 5001) {
    // run the server
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
  }
};