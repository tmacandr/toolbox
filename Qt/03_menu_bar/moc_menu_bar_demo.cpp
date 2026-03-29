/****************************************************************************
** Meta object code from reading C++ file 'menu_bar_demo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu_bar_demo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_bar_demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_menu_bar_demo_t {
    QByteArrayData data[15];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_bar_demo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_bar_demo_t qt_meta_stringdata_menu_bar_demo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "menu_bar_demo"
QT_MOC_LITERAL(1, 14, 17), // "count_action_slot"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "exit_action_slot"
QT_MOC_LITERAL(4, 50, 19), // "zoom_in_action_slot"
QT_MOC_LITERAL(5, 70, 20), // "zoom_out_action_slot"
QT_MOC_LITERAL(6, 91, 22), // "move_north_action_slot"
QT_MOC_LITERAL(7, 114, 22), // "move_south_action_slot"
QT_MOC_LITERAL(8, 137, 21), // "move_east_action_slot"
QT_MOC_LITERAL(9, 159, 21), // "move_west_action_slot"
QT_MOC_LITERAL(10, 181, 18), // "libRef_action_slot"
QT_MOC_LITERAL(11, 200, 22), // "population_action_slot"
QT_MOC_LITERAL(12, 223, 20), // "drainage_action_slot"
QT_MOC_LITERAL(13, 244, 23), // "polit_ocean_action_slot"
QT_MOC_LITERAL(14, 268, 16) // "help_action_slot"

    },
    "menu_bar_demo\0count_action_slot\0\0"
    "exit_action_slot\0zoom_in_action_slot\0"
    "zoom_out_action_slot\0move_north_action_slot\0"
    "move_south_action_slot\0move_east_action_slot\0"
    "move_west_action_slot\0libRef_action_slot\0"
    "population_action_slot\0drainage_action_slot\0"
    "polit_ocean_action_slot\0help_action_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu_bar_demo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void menu_bar_demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<menu_bar_demo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->count_action_slot(); break;
        case 1: _t->exit_action_slot(); break;
        case 2: _t->zoom_in_action_slot(); break;
        case 3: _t->zoom_out_action_slot(); break;
        case 4: _t->move_north_action_slot(); break;
        case 5: _t->move_south_action_slot(); break;
        case 6: _t->move_east_action_slot(); break;
        case 7: _t->move_west_action_slot(); break;
        case 8: _t->libRef_action_slot(); break;
        case 9: _t->population_action_slot(); break;
        case 10: _t->drainage_action_slot(); break;
        case 11: _t->polit_ocean_action_slot(); break;
        case 12: _t->help_action_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject menu_bar_demo::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_menu_bar_demo.data,
    qt_meta_data_menu_bar_demo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *menu_bar_demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu_bar_demo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_menu_bar_demo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int menu_bar_demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
