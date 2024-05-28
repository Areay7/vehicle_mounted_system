/****************************************************************************
** Meta object code from reading C++ file 'currentsituation.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../weather/currentsituation.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'currentsituation.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCurrentSituationENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCurrentSituationENDCLASS = QtMocHelpers::stringData(
    "CurrentSituation",
    "setClientPort",
    "",
    "p",
    "updateLogStateChange",
    "brokerDisconnected",
    "on_btn_Subscribe_clicked",
    "on_btn_Publish_clicked",
    "updateMessage",
    "QMqttMessage",
    "msg",
    "updateStatus",
    "QMqttSubscription::SubscriptionState",
    "state",
    "on_btnOpenMainWidget_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCurrentSituationENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[17];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[21];
    char stringdata5[19];
    char stringdata6[25];
    char stringdata7[23];
    char stringdata8[14];
    char stringdata9[13];
    char stringdata10[4];
    char stringdata11[13];
    char stringdata12[37];
    char stringdata13[6];
    char stringdata14[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCurrentSituationENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCurrentSituationENDCLASS_t qt_meta_stringdata_CLASSCurrentSituationENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "CurrentSituation"
        QT_MOC_LITERAL(17, 13),  // "setClientPort"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 1),  // "p"
        QT_MOC_LITERAL(34, 20),  // "updateLogStateChange"
        QT_MOC_LITERAL(55, 18),  // "brokerDisconnected"
        QT_MOC_LITERAL(74, 24),  // "on_btn_Subscribe_clicked"
        QT_MOC_LITERAL(99, 22),  // "on_btn_Publish_clicked"
        QT_MOC_LITERAL(122, 13),  // "updateMessage"
        QT_MOC_LITERAL(136, 12),  // "QMqttMessage"
        QT_MOC_LITERAL(149, 3),  // "msg"
        QT_MOC_LITERAL(153, 12),  // "updateStatus"
        QT_MOC_LITERAL(166, 36),  // "QMqttSubscription::Subscripti..."
        QT_MOC_LITERAL(203, 5),  // "state"
        QT_MOC_LITERAL(209, 28)   // "on_btnOpenMainWidget_clicked"
    },
    "CurrentSituation",
    "setClientPort",
    "",
    "p",
    "updateLogStateChange",
    "brokerDisconnected",
    "on_btn_Subscribe_clicked",
    "on_btn_Publish_clicked",
    "updateMessage",
    "QMqttMessage",
    "msg",
    "updateStatus",
    "QMqttSubscription::SubscriptionState",
    "state",
    "on_btnOpenMainWidget_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCurrentSituationENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    0,   66,    2, 0x08,    4 /* Private */,
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    1,   69,    2, 0x08,    7 /* Private */,
      11,    1,   72,    2, 0x08,    9 /* Private */,
      14,    0,   75,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CurrentSituation::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSCurrentSituationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCurrentSituationENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCurrentSituationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CurrentSituation, std::true_type>,
        // method 'setClientPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateLogStateChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'brokerDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Subscribe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Publish_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMqttMessage &, std::false_type>,
        // method 'updateStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMqttSubscription::SubscriptionState, std::false_type>,
        // method 'on_btnOpenMainWidget_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CurrentSituation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CurrentSituation *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setClientPort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->updateLogStateChange(); break;
        case 2: _t->brokerDisconnected(); break;
        case 3: _t->on_btn_Subscribe_clicked(); break;
        case 4: _t->on_btn_Publish_clicked(); break;
        case 5: _t->updateMessage((*reinterpret_cast< std::add_pointer_t<QMqttMessage>>(_a[1]))); break;
        case 6: _t->updateStatus((*reinterpret_cast< std::add_pointer_t<QMqttSubscription::SubscriptionState>>(_a[1]))); break;
        case 7: _t->on_btnOpenMainWidget_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMqttMessage >(); break;
            }
            break;
        }
    }
}

const QMetaObject *CurrentSituation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentSituation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCurrentSituationENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CurrentSituation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
