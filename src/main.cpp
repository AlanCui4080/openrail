#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QtWidgets/QWidget>

#include <boost/multi_array.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <spdlog/spdlog.h>
namespace orail
{
    namespace detail
    {
        enum class pathway_type
        {
            OPEN,
            BLOCKED,
            WAITING,
        };
    }
    class pathway : boost::array<detail::pathway_type, 8>
    {
    public:
        using type = detail::pathway_type;
    };
    class router
    {
    public:
        enum class type
        {
            CONNECTION,
            TURNOUT,
            SIGNAL
        };
    };
    class tile
    {
    public:
    private:
        boost::optional<router> m_router;
        pathway                 inbound_pathway;
        pathway                 outbound_pathway;
    };
    class map
    {
    public:
        using array_type = boost::array<boost::array<tile, 128>, 128>;

    private:
        array_type m_data;

    public:
        map(){};
    };
} // namespace orail
using namespace orail;
int main(int argc, char* argv[])
{
    spdlog::info("Openrail beta version.");
    spdlog::info("Copyright (C) 2023 AlanCui4080");
    // clang-format off
    spdlog::info("This is free software; see the source for copying conditions.");
    spdlog::info("There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.");
    // clang-format on
    QApplication a(argc, argv);
    MainWindow   w;
    w.show();
    return a.exec();
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
