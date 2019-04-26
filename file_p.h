%{Cpp:LicenseTemplate}\
#include "%{HdrFileName}"
%{JS: Cpp.openNamespaces('%{Class}')}
@if %{isQObject}
class %{CN}::Private : public QObject
@else
class %{CN}::Private
@endif
{
@if %{isQObject}
    Q_OBJECT
@endif

public:
    Private(%{CN} *parent);

    %{CN} *q;
};
%{JS: Cpp.closeNamespaces('%{Class}')}\
