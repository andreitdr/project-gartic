#pragma once
#include <QMainWindow>
#include "ui_JoinRoom.h"
#include "../../API/Contexts/Contexts.h"

class JoinRoom : public QMainWindow
{
	Q_OBJECT

public:
	explicit JoinRoom(Contexts* contexts, QWidget *parent = nullptr);
	~JoinRoom();

private:
	Ui::JoinRoomClass ui;
	Contexts* contexts;

signals:
	void goToJoinGameWindow();
	void goToLobbyWindow();
	void sendLobbyId(int lobbyId);
	void windowPositionChanged(const QPoint& newPosition);

private slots:
	virtual void on_pushButton_goBack_clicked();
	virtual void on_pushButton_JoinPrivateRoom_clicked();
	virtual void on_pushButton_JoinRandomGame_clicked();
};
