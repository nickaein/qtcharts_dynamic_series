#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <thread>
#include <QtCharts/QVXYModelMapper>

#include "mydatamodel.h"


void point_generator_proc(MyDataModel* model)
{
	for(double t=0 ; ; t+=1)
	{
		double v = (1 + sin(t/10.0)) / 2.0;

		model->addNewPoint(std::make_pair(t, v));

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	auto context = engine.rootContext();

	MyDataModel* myDataModel = new MyDataModel();

	QtCharts::QVXYModelMapper* mapper = new QtCharts::QVXYModelMapper();
	mapper->setModel(myDataModel);
	mapper->setXColumn(0);
	mapper->setYColumn(1);

	std::thread point_generator_thread(point_generator_proc, myDataModel);

	context->setContextProperty("mapper", mapper);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
