#include "asintf.h"

using namespace Appstream;

AsIntf::AsIntf(QObject *parent) :
    QObject(parent)
{
    asdb = new Appstream::Database(this);
    asdb->open();
}

QQmlListProperty<Appstream::Component>
AsIntf::getAllComponents()
{
    m_cpts = asdb->getAllComponents();

    QQmlListProperty<Appstream::Component> list(this, m_cpts);
    return list;
}

QQmlListProperty<Appstream::Component>
AsIntf::getAllDesktopApps()
{
    m_cpts = asdb->getComponentsByKind(Component::KindDesktop);

    QQmlListProperty<Appstream::Component> list(this, m_cpts);
    return list;
}
