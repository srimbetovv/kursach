#include "summaryscreen.h"

SummaryScreen::SummaryScreen(QString score)
{
    QPixmap menuBackground(":/res/backgrounforgame.png");
    setBackgroundBrush(menuBackground);

    message = new QGraphicsTextItem;

    message->setPlainText(QString("YOU LOSE, PLAYER.\n\nYOUR SCORE: %1").arg(score));
    message->setFont(Utils::getCommonFont(Settings::MenuFontSize));
    message->setPos(Settings::WindowWidth/2 - message->boundingRect().width()/2,Settings::WindowHeight/3);
    addItem(message);

    playAgainButton = new MenuButton(QString("PLAY AGAIN"));
    playAgainButton->setPos(Settings::WindowWidth/2 - playAgainButton->boundingRect().width()/2,Settings::WindowHeight - playAgainButton->boundingRect().height());
    addItem(playAgainButton);
}

SummaryScreen::~SummaryScreen()
{
    delete playAgainButton;
    delete message;
}

void SummaryScreen::updateScore(QString score)
{
      message->setPlainText(QString("YOU LOSE, PLAYER.\n\nYOUR SCORE: %1").arg(score));
}
