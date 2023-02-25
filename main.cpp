#include <QApplication>
#include <QPushButton>


class provaClass : QWidget{
private:
    QString string;
public:
    provaClass(QString &string) :string(string) {}
    QString get(){
        return string;
    }
};
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString s1("First Commit");
    provaClass s(s1);
    QPushButton button(s.get(), nullptr);
    button.resize(500, 500);
    button.show();
    return QApplication::exec();
}
