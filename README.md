# qtcharts_dynamic_series
Sample project that add points to a [QML chart](https://doc.qt.io/qt-5/qtcharts-qmlmodule.html) dynamically from C++

This is sample/minimal application which demonstrates how new points for a [QML LineSeries](https://doc.qt.io/qt-5/qml-qtcharts-lineseries.html) can be added dynamically (during runtime) either from another C++ thread or from the QML itself. The application uses [QAbstractTableModel](https://doc.qt.io/qt-5/qabstracttablemodel.html) as base data model for the Lineseries.

There was a [threading bug](https://bugreports.qt.io/browse/QTBUG-55272) in the [initial version](https://github.com/nickaein/qtcharts_dynamic_series/commit/78b21b5a29e4611d89d7d91be3d730a9e37456b4) that has been fixed.
