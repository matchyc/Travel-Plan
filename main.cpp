#include "mainwindow.h"
#include <QApplication>
#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>
#include <QTextCodec>
#include <QMutex>
#include <QTime>
#include <QDateTime>


void MessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
 {
    static QMutex mutex;
    mutex.lock();

     QByteArray localMsg = msg.toLocal8Bit();
     switch (type) {
     case QtDebugMsg:
         fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtInfoMsg:
         fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtWarningMsg:
         fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtCriticalMsg:
         fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtFatalMsg:
         fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     }
     if(type == QtDebugMsg)
     {
         QFile file("log.txt");
         localMsg.append('\n');
         file.open(QIODevice::ReadWrite | QIODevice::Append);
         QTextStream fs(&file);
         fs.setCodec("utf8");
         fs << msg << endl;
         file.close();
     }


    mutex.unlock();
 }


int main(int argc, char *argv[])
{

    qInstallMessageHandler(MessageOutput);

    qDebug() << "本次启动旅行计划时间为：" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm::ss ddd") ;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
