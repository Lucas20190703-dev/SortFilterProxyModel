#include "filter.h"
#include "valuefilter.h"
#include "indexfilter.h"
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include "regexpfilter.h"
#else
#include "regularexpressionfilter.h"
#endif
#include "rangefilter.h"
#include "expressionfilter.h"
#include "anyoffilter.h"
#include "alloffilter.h"
#include <QQmlEngine>
#include <QCoreApplication>

namespace qqsfpm {

void registerFiltersTypes() {
    qmlRegisterUncreatableType<Filter>("SortFilterProxyModel", 0, 2, "Filter", "Filter is an abstract class");
    qmlRegisterType<ValueFilter>("SortFilterProxyModel", 0, 2, "ValueFilter");
    qmlRegisterType<IndexFilter>("SortFilterProxyModel", 0, 2, "IndexFilter");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    qmlRegisterType<RegExpFilter>("SortFilterProxyModel", 0, 2, "RegExpFilter");
#else
    qmlRegisterType<RegularExpressionFilter>("SortFilterProxyModel", 0, 2, "RegularExpressionFilter");
#endif
    qmlRegisterType<RangeFilter>("SortFilterProxyModel", 0, 2, "RangeFilter");
    qmlRegisterType<ExpressionFilter>("SortFilterProxyModel", 0, 2, "ExpressionFilter");
    qmlRegisterType<AnyOfFilter>("SortFilterProxyModel", 0, 2, "AnyOf");
    qmlRegisterType<AllOfFilter>("SortFilterProxyModel", 0, 2, "AllOf");
    qmlRegisterUncreatableType<FilterContainerAttached>("SortFilterProxyModel", 0, 2, "FilterContainer", "FilterContainer can only be used as an attaching type");
}

Q_COREAPP_STARTUP_FUNCTION(registerFiltersTypes)

}
