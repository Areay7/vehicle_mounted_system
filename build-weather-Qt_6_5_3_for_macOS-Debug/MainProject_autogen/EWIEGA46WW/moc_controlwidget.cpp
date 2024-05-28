/****************************************************************************
** Meta object code from reading C++ file 'controlwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../weather/controlwidget.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSControlWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControlWidgetENDCLASS = QtMocHelpers::stringData(
    "ControlWidget",
    "returnToMainWidget",
    "",
    "on_pushButtonSetLED_clicked",
    "on_pushButtonSetDoor_clicked",
    "on_pushButtonSetMode_clicked",
    "on_pushButtonTemperSw_clicked",
    "on_pushButtonAdd_pressed",
    "on_pushButtonAdd_released",
    "on_pushButtonSub_pressed",
    "on_pushButtonSub_released",
    "on_pushButtonHumSw_clicked",
    "on_pushButtonSetHumAdd_pressed",
    "on_pushButtonSetHumAdd_released",
    "on_pushButtonSetHumSub_pressed",
    "on_pushButtonSetHumSub_released",
    "timerTimeOut",
    "on_pushButtonSetWIFI_clicked",
    "on_pushButtonSetBlue_clicked",
    "on_pushButtonEdit_clicked",
    "on_pushButtonVoice_pressed",
    "on_pushButtonVoice_released"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControlWidgetENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[14];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[29];
    char stringdata5[29];
    char stringdata6[30];
    char stringdata7[25];
    char stringdata8[26];
    char stringdata9[25];
    char stringdata10[26];
    char stringdata11[27];
    char stringdata12[31];
    char stringdata13[32];
    char stringdata14[31];
    char stringdata15[32];
    char stringdata16[13];
    char stringdata17[29];
    char stringdata18[29];
    char stringdata19[26];
    char stringdata20[27];
    char stringdata21[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControlWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControlWidgetENDCLASS_t qt_meta_stringdata_CLASSControlWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ControlWidget"
        QT_MOC_LITERAL(14, 18),  // "returnToMainWidget"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 27),  // "on_pushButtonSetLED_clicked"
        QT_MOC_LITERAL(62, 28),  // "on_pushButtonSetDoor_clicked"
        QT_MOC_LITERAL(91, 28),  // "on_pushButtonSetMode_clicked"
        QT_MOC_LITERAL(120, 29),  // "on_pushButtonTemperSw_clicked"
        QT_MOC_LITERAL(150, 24),  // "on_pushButtonAdd_pressed"
        QT_MOC_LITERAL(175, 25),  // "on_pushButtonAdd_released"
        QT_MOC_LITERAL(201, 24),  // "on_pushButtonSub_pressed"
        QT_MOC_LITERAL(226, 25),  // "on_pushButtonSub_released"
        QT_MOC_LITERAL(252, 26),  // "on_pushButtonHumSw_clicked"
        QT_MOC_LITERAL(279, 30),  // "on_pushButtonSetHumAdd_pressed"
        QT_MOC_LITERAL(310, 31),  // "on_pushButtonSetHumAdd_released"
        QT_MOC_LITERAL(342, 30),  // "on_pushButtonSetHumSub_pressed"
        QT_MOC_LITERAL(373, 31),  // "on_pushButtonSetHumSub_released"
        QT_MOC_LITERAL(405, 12),  // "timerTimeOut"
        QT_MOC_LITERAL(418, 28),  // "on_pushButtonSetWIFI_clicked"
        QT_MOC_LITERAL(447, 28),  // "on_pushButtonSetBlue_clicked"
        QT_MOC_LITERAL(476, 25),  // "on_pushButtonEdit_clicked"
        QT_MOC_LITERAL(502, 26),  // "on_pushButtonVoice_pressed"
        QT_MOC_LITERAL(529, 27)   // "on_pushButtonVoice_released"
    },
    "ControlWidget",
    "returnToMainWidget",
    "",
    "on_pushButtonSetLED_clicked",
    "on_pushButtonSetDoor_clicked",
    "on_pushButtonSetMode_clicked",
    "on_pushButtonTemperSw_clicked",
    "on_pushButtonAdd_pressed",
    "on_pushButtonAdd_released",
    "on_pushButtonSub_pressed",
    "on_pushButtonSub_released",
    "on_pushButtonHumSw_clicked",
    "on_pushButtonSetHumAdd_pressed",
    "on_pushButtonSetHumAdd_released",
    "on_pushButtonSetHumSub_pressed",
    "on_pushButtonSetHumSub_released",
    "timerTimeOut",
    "on_pushButtonSetWIFI_clicked",
    "on_pushButtonSetBlue_clicked",
    "on_pushButtonEdit_clicked",
    "on_pushButtonVoice_pressed",
    "on_pushButtonVoice_released"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControlWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  134,    2, 0x0a,    1 /* Public */,
       3,    0,  135,    2, 0x08,    2 /* Private */,
       4,    0,  136,    2, 0x08,    3 /* Private */,
       5,    0,  137,    2, 0x08,    4 /* Private */,
       6,    0,  138,    2, 0x08,    5 /* Private */,
       7,    0,  139,    2, 0x08,    6 /* Private */,
       8,    0,  140,    2, 0x08,    7 /* Private */,
       9,    0,  141,    2, 0x08,    8 /* Private */,
      10,    0,  142,    2, 0x08,    9 /* Private */,
      11,    0,  143,    2, 0x08,   10 /* Private */,
      12,    0,  144,    2, 0x08,   11 /* Private */,
      13,    0,  145,    2, 0x08,   12 /* Private */,
      14,    0,  146,    2, 0x08,   13 /* Private */,
      15,    0,  147,    2, 0x08,   14 /* Private */,
      16,    0,  148,    2, 0x08,   15 /* Private */,
      17,    0,  149,    2, 0x08,   16 /* Private */,
      18,    0,  150,    2, 0x08,   17 /* Private */,
      19,    0,  151,    2, 0x08,   18 /* Private */,
      20,    0,  152,    2, 0x08,   19 /* Private */,
      21,    0,  153,    2, 0x08,   20 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ControlWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSControlWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControlWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSControlWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ControlWidget, std::true_type>,
        // method 'returnToMainWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetLED_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetDoor_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetMode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonTemperSw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAdd_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAdd_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSub_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSub_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonHumSw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetHumAdd_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetHumAdd_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetHumSub_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetHumSub_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timerTimeOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetWIFI_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSetBlue_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonEdit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonVoice_pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonVoice_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->returnToMainWidget(); break;
        case 1: _t->on_pushButtonSetLED_clicked(); break;
        case 2: _t->on_pushButtonSetDoor_clicked(); break;
        case 3: _t->on_pushButtonSetMode_clicked(); break;
        case 4: _t->on_pushButtonTemperSw_clicked(); break;
        case 5: _t->on_pushButtonAdd_pressed(); break;
        case 6: _t->on_pushButtonAdd_released(); break;
        case 7: _t->on_pushButtonSub_pressed(); break;
        case 8: _t->on_pushButtonSub_released(); break;
        case 9: _t->on_pushButtonHumSw_clicked(); break;
        case 10: _t->on_pushButtonSetHumAdd_pressed(); break;
        case 11: _t->on_pushButtonSetHumAdd_released(); break;
        case 12: _t->on_pushButtonSetHumSub_pressed(); break;
        case 13: _t->on_pushButtonSetHumSub_released(); break;
        case 14: _t->timerTimeOut(); break;
        case 15: _t->on_pushButtonSetWIFI_clicked(); break;
        case 16: _t->on_pushButtonSetBlue_clicked(); break;
        case 17: _t->on_pushButtonEdit_clicked(); break;
        case 18: _t->on_pushButtonVoice_pressed(); break;
        case 19: _t->on_pushButtonVoice_released(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControlWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
