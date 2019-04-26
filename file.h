%{Cpp:LicenseTemplate}\
#pragma once

%{JS: QtSupport.qtIncludes([ ( '%{IncludeQObject}' )          ? 'QtCore/%{IncludeQObject}'                 : '',
                             ( '%{IncludeQWidget}' )          ? 'QtGui/%{IncludeQWidget}'                  : '',
                             ( '%{IncludeQMainWindow}' )      ? 'QtGui/%{IncludeQMainWindow}'              : '' ],
                           [ ( '%{IncludeQObject}' )          ? 'QtCore/%{IncludeQObject}'                 : '',
                             ( '%{IncludeQWidget}' )          ? 'QtWidgets/%{IncludeQWidget}'              : '',
                             ( '%{IncludeQMainWindow}' )      ? 'QtWidgets/%{IncludeQMainWindow}'          : '' ])}\
%{JS: Cpp.openNamespaces('%{Class}')}\

@if '%{Base}'
class %{CN} : public %{Base}
@else
class %{CN}
@endif
{
@if %{isQObject}
     Q_OBJECT
@endif

public:
@if '%{Base}' === 'QObject'
    explicit %{CN}(QObject *parent = nullptr);
@elsif '%{Base}' === 'QWidget' || '%{Base}' === 'QMainWindow'
    explicit %{CN}(QWidget *parent = nullptr);
@else
    %{CN}();
    ~%{CN}();
@endif

private:
    class Private;
    Private *d;
};
%{JS: Cpp.closeNamespaces('%{Class}')}\
