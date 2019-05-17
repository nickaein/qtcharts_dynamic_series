import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtCharts 2.0

ApplicationWindow {
    visible: true
    width: 600
    height: 300
    property int timeStep: 0

    ChartView {
        id: chartView
        anchors.fill: parent

        ValueAxis {
            id: axisX
            min: 0
            max: 400
        }

        Component.onCompleted:  {
            mapper.series = series2
        }

        LineSeries {
            id: series1
            axisX: axisX
            name: "From QML"
        }

        LineSeries {
            id: series2
            axisX: axisX
            name: "From C++"
        }
    }

    Timer {
        interval: 100
        repeat: true
        running: true
        onTriggered: {
            timeStep++;
            var y = (1+Math.cos(timeStep/10.0))/2.0;
            series1.append(timeStep, y);
        }
    }
}
