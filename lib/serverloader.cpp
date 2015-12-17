#include "serverloader.h"
using boost::asio::ip::tcp;

ServerLoader::ServerLoader()
{
}

GameData ServerLoader::createGame() const {
    std::string result;
    try {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), ServerLoader::HOST, ServerLoader::PORT);
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);

        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "GET " << "/" << " HTTP/1.0\r\n";
        request_stream << "Host: " << ServerLoader::HOST << "\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: close\r\n\r\n";

        boost::asio::write(socket, request);

        boost::asio::streambuf response;

        boost::asio::read_until(socket, response, "=");

        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);
        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
        {
            GameData data;
            return data;
        }

        std::string str;
        bool nextIsResult = false;
        while(std::getline(response_stream, str)) {
            if(nextIsResult) {
                result = str;
                break;
            }
            qDebug() << QString(str.c_str());
            if(str == "\r") {
                nextIsResult = true;
            }
        }
        qDebug() << "\n";

        boost::system::error_code error;
        while (boost::asio::read(socket, response,
            boost::asio::transfer_at_least(1), error))
            qDebug() << &response;
        if (error != boost::asio::error::eof)
            throw boost::system::system_error(error);
    }
    catch(std::exception &e) {
        qDebug() << "BOOST:" << e.what() << endl;
    }

    GameData data;
    if(result.size() == 0) {
        data.setError("Cannot load cards");
    }
    else
    {
        qDebug() << QString(result.c_str());
        std::istringstream tmp(result);
        std::vector<unsigned short> cards;
        unsigned short tmpCard;

        char delimiter;
        for(size_t i = 0; i < ServerLoader::CARDS_PER_USER * ServerLoader::USERS + ServerLoader::CARDS_FIELD; i++) {
            tmp >> tmpCard;
            cards.push_back(tmpCard);
            qDebug() << cards[i];
            if(i != ServerLoader::CARDS_PER_USER * ServerLoader::USERS + ServerLoader::CARDS_FIELD - 1) {
                tmp >> delimiter;
            }
        }

        if(cards.size() < ServerLoader::CARDS_PER_USER * ServerLoader::USERS + ServerLoader::CARDS_FIELD) {
            data.setError("Server error");
        }
        else
        {
            for(size_t i = 0; i < ServerLoader::CARDS_FIELD; i++) {
                data.getFieldCards().push_back(cards[i]);
            }
            if(ServerLoader::USERS == 2) {
                for(size_t i = ServerLoader::CARDS_FIELD; i < ServerLoader::CARDS_FIELD + ServerLoader::CARDS_PER_USER; i++) {
                    data.getPlayerCards().push_back(cards[i]);
                }
                for(size_t i = ServerLoader::CARDS_FIELD + ServerLoader::CARDS_PER_USER; i < ServerLoader::CARDS_FIELD + ServerLoader::CARDS_PER_USER * 2; i++) {
                    data.getServerCards().push_back(cards[i]);
                }
            }
        }
    }

    return data;
}
