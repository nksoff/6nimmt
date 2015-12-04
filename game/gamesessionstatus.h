#ifndef GAMESESSIONSTATUS
#define GAMESESSIONSTATUS

enum GameSessionStatus {
    GAME_SESSION_NOT_STARTED,   // не началась
    GAME_SESSION_WAITING,       // ожидание хода
    GAME_SESSION_RENDERING,     // отрисовка
    GAME_SESSION_FINISHED       // завершилась
};

#endif // GAMESESSIONSTATUS

