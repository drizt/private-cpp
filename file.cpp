%{Cpp:LicenseTemplate}\
#include "%{PHdrFileName}"
%{JS: Cpp.openNamespaces('%{Class}')}
@if '%{Base}' === 'QObject'
%{CN}::Private::Private(%{CN} *parent)
    : QObject(parent)
    , q(parent)
@else
%{CN}::%{CN}(%{CN} *parent)
    : q(parent)
@endif
{
}

@if '%{Base}' === 'QObject'
%{CN}::%{CN}(QObject *parent)
    : QObject(parent)
    , d(new Private(this))
@elsif '%{Base}' === 'QWidget' || '%{Base}' === 'QMainWindow'
%{CN}::%{CN}(QWidget *parent)
    : %{Base}(parent)
@else
%{CN}::%{CN}()
@endif
{
}

@if !%{isQObject}
%{CN}::~%{CN}()
{
    delete d;
}
@endif
%{JS: Cpp.closeNamespaces('%{Class}')}\
