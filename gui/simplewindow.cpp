#include "simplewindow.h"

#include <iostream>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QImage>
#include <QGuiApplication>  // For QGuiApplication
#include <QApplication>  // For QGuiApplication
#include <QTimer>

#include "gui/qcanvas.h"

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent)
{

    auto outer = new QVBoxLayout(this);

    QImage qim = SimpleWindow::MatToQPixmap(canvas.getImage());
    noteLabel->setPixmap(QPixmap::fromImage(qim));

    noteLabel->setStyleSheet("border: 1px solid black");

    connect(noteLabel, &QCanvas::mousePressed, this, &SimpleWindow::onMousePressed);
    connect(noteLabel, &QCanvas::mouseMoved, this, &SimpleWindow::onMouseMoved);
    connect(noteLabel, &QCanvas::mouseReleased, this, &SimpleWindow::onMouseReleased);

    outer->addWidget(noteLabel);

    // auto noteEdit = new QTextEdit(this);
    // outer->addWidget(noteEdit);
    auto btncols = new QVBoxLayout;
    auto drawbtns = new QHBoxLayout;
    btncols->addLayout(drawbtns);

    drawbtns->addWidget(fdBtn);
    drawbtns->addWidget(rdBtn);
    drawbtns->addWidget(clBtn);
    drawbtns->addWidget(ltBtn);

    drawbtns->addWidget(rgbBtn);


    connect(fdBtn, &QPushButton::clicked, this, &SimpleWindow::changeTool);
    connect(rdBtn, &QPushButton::clicked, this, &SimpleWindow::changeTool);
    connect(clBtn, &QPushButton::clicked, this, &SimpleWindow::changeTool);
    connect(ltBtn, &QPushButton::clicked, this, &SimpleWindow::changeTool);
    connect(clrPick, &color_widgets::ColorDialog::colorSelected, this, &SimpleWindow::changeColor);

    connect(rgbBtn, &QPushButton::clicked, [=]{
        clrPick->show();
    });

    connect(scRedo, SIGNAL(activated()), this, SLOT(redo()));
    connect(scUndo, SIGNAL(activated()), this, SLOT(undo()));

    auto inner = new QHBoxLayout;
    outer->addLayout(inner);

    inner->addLayout(btncols);

    auto clearBtn = new QPushButton("Clear");
    inner->addWidget(clearBtn);

    auto saveBtn = new QPushButton("Save");
    inner->addWidget(saveBtn);


    QTimer *timer = new QTimer(noteLabel);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

}

QImage SimpleWindow::MatToQPixmap(const cv::Mat &image) {
    // Check if image is empty
    if (image.empty()) {
        std::cerr << "Empty image" << std::endl;
        return QImage();
    }

    // Convert the cv::Mat to QImage
    QImage qimage;

    // For color images (CV_8UC3, RGB format)
    if (image.type() == CV_8UC3) {
        // cv::Mat rgb;
        // cv::cvtColor(image, rgb, cv::COLOR_BGR2RGB); // Convert BGR to RGB
        //image.copyTo(rgb);
        cv::Mat rgb(image.size(), image.type());
        int from_to[] = {0, 2, 1, 1, 2, 0}; // BGR to RGB mapping
        cv::mixChannels(&image, 1, &rgb, 1, from_to, 3);
        qimage = QImage(rgb.data, rgb.cols, rgb.rows, static_cast<int>(rgb.step), QImage::Format_RGB888).copy();
    }
    // For grayscale images (CV_8UC1)
    else if (image.type() == CV_8UC1) {
        qimage = QImage(image.data, image.cols, image.rows, static_cast<int>(image.step), QImage::Format_Grayscale8);
    }
    // Handle other types if needed (e.g., CV_8UC4, CV_16UC3, etc.)
    else {
        std::cerr << "Unsupported image format" << std::endl;
        return QImage();
    }

    // Convert QImage to QPixmap
    //QPixmap pixmap = QPixmap::fromImage(qimage);

    // Check if pixmap conversion is successful
    // if (pixmap.isNull()) {
    //     std::cerr << "Failed to convert cv::Mat to QPixmap." << std::endl;
    // }

    return qimage;
}
