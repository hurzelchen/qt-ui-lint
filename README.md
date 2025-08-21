# qt-ui-lint - A linter for Qt UI files
Using [Qt Designer](https://doc.qt.io/qt-6/qtdesigner-manual.html) in a project might lead to
unintentially large diffs between changes, as Qt Designer does not have a determinitic way of
sorting its generated XML.

This project is an attempt of getting some determinism into these files by sorting them without
breaking the internals of the XML.
