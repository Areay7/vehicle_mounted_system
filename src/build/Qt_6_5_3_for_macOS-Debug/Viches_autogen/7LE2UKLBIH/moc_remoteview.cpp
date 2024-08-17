/****************************************************************************
** Meta object code from reading C++ file 'remoteview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../weather/remote/remoteview.h"
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
#error "The header file 'remoteview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRemoteViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRemoteViewENDCLASS = QtMocHelpers::stringData(
    "RemoteView",
    "on_btn_request_clicked",
    "",
    "onDownloadFinished",
    "onReplyFinished",
    "QNetworkReply*",
    "reply",
    "onLinkClicked",
    "url",
    "onViewFile",
    "onDownloadFile",
    "onCustomContextMenuRequested",
    "pos"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRemoteViewENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[16];
    char stringdata5[15];
    char stringdata6[6];
    char stringdata7[14];
    char stringdata8[4];
    char stringdata9[11];
    char stringdata10[15];
    char stringdata11[29];
    char stringdata12[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRemoteViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRemoteViewENDCLASS_t qt_meta_stringdata_CLASSRemoteViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "RemoteView"
        QT_MOC_LITERAL(11, 22),  // "on_btn_request_clicked"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 18),  // "onDownloadFinished"
        QT_MOC_LITERAL(54, 15),  // "onReplyFinished"
        QT_MOC_LITERAL(70, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(85, 5),  // "reply"
        QT_MOC_LITERAL(91, 13),  // "onLinkClicked"
        QT_MOC_LITERAL(105, 3),  // "url"
        QT_MOC_LITERAL(109, 10),  // "onViewFile"
        QT_MOC_LITERAL(120, 14),  // "onDownloadFile"
        QT_MOC_LITERAL(135, 28),  // "onCustomContextMenuRequested"
        QT_MOC_LITERAL(164, 3)   // "pos"
    },
    "RemoteView",
    "on_btn_request_clicked",
    "",
    "onDownloadFinished",
    "onReplyFinished",
    "QNetworkReply*",
    "reply",
    "onLinkClicked",
    "url",
    "onViewFile",
    "onDownloadFile",
    "onCustomContextMenuRequested",
    "pos"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRemoteViewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       7,    1,   61,    2, 0x08,    5 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    1,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QUrl,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject RemoteView::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSRemoteViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRemoteViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRemoteViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RemoteView, std::true_type>,
        // method 'on_btn_request_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDownloadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onReplyFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onLinkClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'onViewFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDownloadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCustomContextMenuRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>
    >,
    nullptr
} };

void RemoteView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RemoteView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_request_clicked(); break;
        case 1: _t->onDownloadFinished(); break;
        case 2: _t->onReplyFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 3: _t->onLinkClicked((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 4: _t->onViewFile(); break;
        case 5: _t->onDownloadFile(); break;
        case 6: _t->onCustomContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *RemoteView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRemoteViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RemoteView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
