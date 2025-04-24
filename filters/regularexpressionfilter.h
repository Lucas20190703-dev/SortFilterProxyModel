#ifndef REGULAREXPRESSIONFILTER_H
#define REGULAREXPRESSIONFILTER_H

#include "rolefilter.h"
#include <QRegularExpression>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
namespace qqsfpm {

    class RegularExpressionFilter : public RoleFilter {
        Q_OBJECT
        Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged)
        Q_PROPERTY(int patternOptions READ patternOptions WRITE setPatternOptions NOTIFY patternOptionsChanged)

    public:
        enum class PatternOption {
            NoPatternOption = QRegularExpression::NoPatternOption,
            CaseSensitiveOption = QRegularExpression::CaseInsensitiveOption,
            DotMatchesEverythingOption = QRegularExpression::DotMatchesEverythingOption,
            MultilineOption = QRegularExpression::MultilineOption,
            ExtendedPatternSyntaxOption = QRegularExpression::ExtendedPatternSyntaxOption,
            InvertedGreedinessOption = QRegularExpression::InvertedGreedinessOption,
            DontCaptureOption = QRegularExpression::DontCaptureOption,
            UseUnicodePropertiesOption = QRegularExpression::UseUnicodePropertiesOption
        };
        Q_ENUMS(PatternOption)

            using RoleFilter::RoleFilter;

        QString pattern() const;
        void setPattern(const QString& pattern);

        int patternOptions() const;
        void setPatternOptions(int options);

    protected:
        bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

    Q_SIGNALS:
        void patternChanged();
        void patternOptionsChanged();

    private:
        QRegularExpression m_regExp;

        QRegularExpression::PatternOptions m_patternOptions = m_regExp.patternOptions();
        QString m_pattern = m_regExp.pattern();
    };

}

#endif

#endif // REGULAREXPRESSIONFILTER_H
