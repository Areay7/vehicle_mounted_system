/****************************************************************************
** Meta object code from reading C++ file 'wifilistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../weather/wifilistwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifilistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSwifiListWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSwifiListWidgetENDCLASS = QtMocHelpers::stringData(
    "wifiListWidget",
    "connectToWiFi",
    "",
    "keyBoardEdit",
    "keyBoardCancel",
    "keyBoardAwaken",
    "disconnectToWiFi",
    "onButtonClicked",
    "text",
    "on_listWidgetWIFI_itemClicked",
    "QListWidgetItem*",
    "item",
    "readProcessOutput",
    "timerTimeOut"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSwifiListWidgetENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[17];
    char stringdata7[16];
    char stringdata8[5];
    char stringdata9[30];
    char stringdata10[17];
    char stringdata11[5];
    char stringdata12[18];
    char stringdata13[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSwifiListWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSwifiListWidgetENDCLASS_t qt_meta_stringdata_CLASSwifiListWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "wifiListWidget"
        QT_MOC_LITERAL(15, 13),  // "connectToWiFi"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 12),  // "keyBoardEdit"
        QT_MOC_LITERAL(43, 14),  // "keyBoardCancel"
        QT_MOC_LITERAL(58, 14),  // "keyBoardAwaken"
        QT_MOC_LITERAL(73, 16),  // "disconnectToWiFi"
        QT_MOC_LITERAL(90, 15),  // "onButtonClicked"
        QT_MOC_LITERAL(106, 4),  // "text"
        QT_MOC_LITERAL(111, 29),  // "on_listWidgetWIFI_itemClicked"
        QT_MOC_LITERAL(141, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(158, 4),  // "item"
        QT_MOC_LITERAL(163, 17),  // "readProcessOutput"
        QT_MOC_LITERAL(181, 12)   // "timerTimeOut"
    },
    "wifiListWidget",
    "connectToWiFi",
    "",
    "keyBoardEdit",
    "keyBoardCancel",
    "keyBoardAwaken",
    "disconnectToWiFi",
    "onButtonClicked",
    "text",
    "on_listWidgetWIFI_itemClicked",
    "QListWidgetItem*",
    "item",
    "readProcessOutput",
    "timerTimeOut"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSwifiListWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    1,   73,    2, 0x08,    6 /* Private */,
       9,    1,   76,    2, 0x08,    8 /* Private */,
      12,    0,   79,    2, 0x08,   10 /* Private */,
      13,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject wifiListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSwifiListWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSwifiListWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSwifiListWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<wifiListWidget, std::true_type>,
        // method 'connectToWiFi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyBoardEdit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyBoardCancel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyBoardAwaken'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectToWiFi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_listWidgetWIFI_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'readProcessOutput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timerTimeOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void wifiListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wifiListWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectToWiFi(); break;
        case 1: _t->keyBoardEdit(); break;
        case 2: _t->keyBoardCancel(); break;
        case 3: _t->keyBoardAwaken(); break;
        case 4: _t->disconnectToWiFi(); break;
        case 5: _t->onButtonClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_listWidgetWIFI_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 7: _t->readProcessOutput(); break;
        case 8: _t->timerTimeOut(); break;
        default: ;
        }
    }
}

const QMetaObject *wifiListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wifiListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSwifiListWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int wifiListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
