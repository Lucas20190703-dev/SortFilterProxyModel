#include "regularexpressionfilter.h"
#include <QVariant>

namespace qqsfpm {

    /*!
        \qmltype RegularExpressionFilter
        \inherits RoleFilter
        \inqmlmodule SortFilterProxyModel
        \ingroup Filters
        \brief  Filters rows matching a regular expression.

        A RegularExpressionFilter is a \l RoleFilter that accepts rows matching a regular rexpression.

        In the following example, only rows with their \c lastName role beggining with the content of textfield the will be accepted:
        \code
        TextField {
           id: nameTextField
        }

        SortFilterProxyModel {
           sourceModel: contactModel
           filters: RegularExpressionFilter {
               roleName: "lastName"
               pattern: "^" + nameTextField.displayText
           }
        }
        \endcode
    */

    /*!
        \qmlproperty bool RegularExpressionFilter::pattern

        The pattern used to filter the contents of the source model.

        \sa syntax
    */
    QString RegularExpressionFilter::pattern() const
    {
        return m_pattern;
    }

    void RegularExpressionFilter::setPattern(const QString& pattern)
    {
        if (m_pattern == pattern)
            return;

        m_pattern = pattern;
        m_regExp.setPattern(pattern);
        Q_EMIT patternChanged();
        invalidate();
    }

    int RegularExpressionFilter::patternOptions() const
    {
        return static_cast<int>(m_patternOptions);
    }
    void RegularExpressionFilter::setPatternOptions(int options)
    {
        if (m_patternOptions == static_cast<QRegularExpression::PatternOptions>(options))
        {
            return;
        }
        m_patternOptions = static_cast<QRegularExpression::PatternOptions>(options);
        m_regExp.setPatternOptions(m_patternOptions);
        Q_EMIT patternOptionsChanged();
        invalidate();
    }

    bool RegularExpressionFilter::filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const
    {
        QString string = sourceData(sourceIndex, proxyModel).toString();
        auto res = m_regExp.match(string);
        return res.hasMatch();
    }

}
