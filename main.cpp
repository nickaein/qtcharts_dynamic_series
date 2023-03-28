#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <thread>
#include <QtCharts/QVXYModelMapper>
#include <cmath>
#include "mydatamodel.h"


void point_generator_proc(MyDataModel* model)
{
    for(double t=0 ; ; t+=1)
    {
        double y = (1 + sin(t/10.0)) / 2.0;

        model->handleNewPoint(QPointF(t, y));

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    auto context = engine.rootContext();

    auto myDataModel = new MyDataModel();

    auto mapper = new QtCharts::QVXYModelMapper();
    mapper->setModel(myDataModel);
    mapper->setXColumn(0);
    mapper->setYColumn(1);

    std::thread point_generator_thread(point_generator_proc, myDataModel);
    point_generator_thread.detach();

    context->setContextProperty("mapper", mapper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
