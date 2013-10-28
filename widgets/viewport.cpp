/*
 *  This file is a part of KNOSSOS.
 *
 *  (C) Copyright 2007-2013
 *  Max-Planck-Gesellschaft zur Foerderung der Wissenschaften e.V.
 *
 *  KNOSSOS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 of
 *  the License as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * For further information, visit http://www.knossostool.org or contact
 *     Joergen.Kornfeld@mpimf-heidelberg.mpg.de or
 *     Fabian.Svara@mpimf-heidelberg.mpg.de
 */

#include "knossos-global.h"
#include "viewport.h"
#include "eventmodel.h"
#include "renderer.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "sleeper.h"
#include "functions.h"
#include <QPainter>

extern stateInfo *state;

ResizeButton::ResizeButton(QWidget *parent) : QPushButton(parent) {}

void ResizeButton::enterEvent(QEvent *) {
    setCursor(Qt::SizeFDiagCursor);
}

void ResizeButton::leaveEvent(QEvent *) {
    setCursor(Qt::CrossCursor);
}

Viewport::Viewport(QWidget *parent, int viewportType) :
    QGLWidget(parent), resizeButtonHold(false) {
    delegate = new EventModel();
    /* per default the widget only receives move event when at least one mouse button is pressed
    to change this behaviour we need to track the mouse position */

    this->viewportType = viewportType;

    //this->setMouseTracking(true);
    this->setCursor(Qt::CrossCursor);
    this->setFocusPolicy(Qt::WheelFocus); // this means the widget accepts mouse and keyboard focus. This solves also the problem that viewports had to be clicked before the widget know in which viewport the mouse click occured.


    //moveButton = new QPushButton(this);
   // moveButton->setGeometry(323, 298, 25, 25);

    resizeButton = new ResizeButton(this);
    resizeButton->setIcon(QIcon("resize.gif"));
    resizeButton->show();
    //connect(moveButton, SIGNAL(clicked()), this, SLOT(moveButtonClicked()));
    connect(resizeButton, SIGNAL(pressed()), this, SLOT(resizeButtonClicked()));
    /*
    if(widgetNumber == VIEWPORT_SKELETON) {
        xyButton = new QPushButton("xy", this);
        xyButton->setGeometry(113, 2, 35, 20);
        xzButton = new QPushButton("xz", this);
        xzButton->setGeometry(153, 2, 35, 20);
        yzButton = new QPushButton("yz", this);
        yzButton->setGeometry(193, 2, 35, 20);
        r90Button = new QPushButton("r90", this);
        r90Button->setGeometry(233, 2, 35, 20);
        r180Button = new QPushButton("r180", this);
        r180Button->setGeometry(273, 2, 35, 20);
        resetButton = new QPushButton("reset", this);
        resetButton->setGeometry(313, 2, 35, 20);

        connect(xyButton, SIGNAL(clicked()), this, SLOT(xyButtonClicked()));
        connect(xzButton, SIGNAL(clicked()), this, SLOT(xzButtonClicked()));
        connect(yzButton, SIGNAL(clicked()), this, SLOT(yzButtonClicked()));
        connect(r90Button, SIGNAL(clicked()), this, SLOT(r90ButtonClicked()));
        connect(r180Button, SIGNAL(clicked()), this, SLOT(r180ButtonClicked()));
        connect(resetButton, SIGNAL(clicked()), this, SLOT(resetButtonClicked()));
    }*/
}

void Viewport::initializeGL() {
    // button geometry has to be defined here, because width() and height() return wrong information before initializeGL
    resizeButton->setGeometry(width() - ResizeButton::SIZE, height() - ResizeButton::SIZE, ResizeButton::SIZE, ResizeButton::SIZE);
    if(viewportType < VIEWPORT_SKELETON) {

        glGenTextures(1, &state->viewerState->vpConfigs[viewportType].texture.texHandle);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glBindTexture(GL_TEXTURE_2D, state->viewerState->vpConfigs[viewportType].texture.texHandle);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, state->viewerState->filterType);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, state->viewerState->filterType);

        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        // loads an empty texture into video memory - during user movement, this
        // texture is updated via glTexSubImage2D in vpGenerateTexture & vpHandleBacklog
        // We need GL_RGB as texture internal format to color the textures

        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGB,
                     state->viewerState->vpConfigs[viewportType].texture.edgeLengthPx,
                     state->viewerState->vpConfigs[viewportType].texture.edgeLengthPx,
                     0,
                     GL_RGB,
                     GL_UNSIGNED_BYTE,
                     state->viewerState->defaultTexData);

        //Handle overlay textures.

    }


    // The following code configures openGL to draw into the current VP
    //set the drawing area in the window to our actually processed view port.
    glViewport(state->viewerState->vpConfigs[viewportType].upperLeftCorner.x,
               state->viewerState->vpConfigs[viewportType].upperLeftCorner.y,
               state->viewerState->vpConfigs[viewportType].edgeLength,
               state->viewerState->vpConfigs[viewportType].edgeLength);
    //select the projection matrix
    glMatrixMode(GL_PROJECTION);
    //reset it
    glLoadIdentity();
    //define coordinate system for our viewport: left right bottom top near far
    //coordinate values
    glOrtho(0, state->viewerState->vpConfigs[viewportType].edgeLength,
            state->viewerState->vpConfigs[viewportType].edgeLength, 0, 25, -25);
    //select the modelview matrix for modification
    glMatrixMode(GL_MODELVIEW);
    //reset it
    glLoadIdentity();
    //glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);

    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);



}

void Viewport::initializeOverlayGL() {
    if(viewportType < VIEWPORT_SKELETON) {
        if(state->overlay) {
            glGenTextures(1, &state->viewerState->vpConfigs[viewportType].texture.overlayHandle);
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

            glBindTexture(GL_TEXTURE_2D, state->viewerState->vpConfigs[viewportType].texture.overlayHandle);

            //Set the parameters for the texture.
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, state->viewerState->filterType);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, state->viewerState->filterType);

            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGBA,
                         state->viewerState->vpConfigs[viewportType].texture.edgeLengthPx,
                         state->viewerState->vpConfigs[viewportType].texture.edgeLengthPx,
                         0,
                         GL_RGBA,
                         GL_UNSIGNED_BYTE,
                         state->viewerState->defaultOverlayData);
        }
    }
}

void Viewport::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = (GLfloat)width() / height();

    glFrustum(-x, +x, -1.0, + 1.0, 0.1, 15.0);
    glMatrixMode(GL_MODELVIEW);

    SET_COORDINATE(state->viewerState->vpConfigs[viewportType].upperLeftCorner,
                   geometry().topLeft().x(),
                   geometry().topLeft().y(),
                   0);
    state->viewerState->vpConfigs[viewportType].edgeLength = width();
}

void Viewport::paintGL() {

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


    if(state->viewerState->viewerReady) {
        if(this->viewportType < VIEWPORT_SKELETON) {
           this->drawViewport(viewportType);
        }  else {
            this->drawSkeletonViewport();
        }
    }

}

//functions to determine position x/y relative to last position lastX, lastY
int Viewport::xrel(int x) {
    return (x - this->lastX);
}
int Viewport::yrel(int y) {
    return (y - this->lastY);
}


void Viewport::mouseMoveEvent(QMouseEvent *event) {
    bool clickEvent = false;

    if(QApplication::mouseButtons() == Qt::LeftButton) {
        if(QApplication::keyboardModifiers() == Qt::CTRL) { // drag viewport around
            moveVP(event);
        }
        else if(resizeButtonHold) {// resize viewport
            resizeVP(event);
        }
        else {// delegate behaviour
            handleMouseMotionLeftHold(event, viewportType);
            clickEvent = true;
        }
    } else if(QApplication::mouseButtons() == Qt::MidButton) {
        handleMouseMotionMiddleHold(event, viewportType);
        clickEvent = true;
    } else if(QApplication::mouseButtons() == Qt::RightButton) {
        handleMouseMotionRightHold(event, viewportType);
        clickEvent = true;
    }

    if(clickEvent) {
        delegate->mouseX = event->x();
        delegate->mouseY = event->y();
    }
}

void Viewport::mousePressEvent(QMouseEvent *event) {

    delegate->mouseX = event->x();
    delegate->mouseY = event->y();

    if(event->button() == Qt::LeftButton) {
        if(QApplication::keyboardModifiers() == Qt::CTRL) { // user wants to drag vp
            setCursor(Qt::ClosedHandCursor);
            lastX= event->x();
            lastY = event->y();
            return;
        }
        //this->move(event->x() - this->pos().x(), event->y() - pos().y());
        handleMouseButtonLeft(event, viewportType);
    }
    else if(event->button() == Qt::MidButton) {
        handleMouseButtonMiddle(event, viewportType);
    }
    else if(event->button() == Qt::RightButton) {
        handleMouseButtonRight(event, viewportType);
    }
}

void Viewport::mouseReleaseEvent(QMouseEvent *) {
    resizeButtonHold = false; // can only be true, when left mouse button is pressed
    if(QApplication::keyboardModifiers() == Qt::CTRL) {
        setCursor(Qt::OpenHandCursor);
    }
    else if(cursor().shape() != Qt::CrossCursor) {
        setCursor(Qt::CrossCursor);
    }
    if(state->viewerState->moveVP != -1)
        state->viewerState->moveVP = -1;
    if(state->viewerState->resizeVP != -1)
        state->viewerState->resizeVP = -1;

    for(int i = 0; i < state->viewerState->numberViewports; i++) {
        state->viewerState->vpConfigs[i].draggedNode = NULL;
        state->viewerState->vpConfigs[i].motionTracking = false;
        state->viewerState->vpConfigs[i].VPmoves = false;
        state->viewerState->vpConfigs[i].VPresizes = false;
        state->viewerState->vpConfigs[i].userMouseSlideX = 0.;
        state->viewerState->vpConfigs[i].userMouseSlideY = 0.;
    }

}

void Viewport::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Control) {
        setCursor(Qt::CrossCursor);
    }
    if(state->keyD) {
        state->keyD = false;
        qDebug() << "D released";
    }else if(state->keyF) {
        state->keyF = false;
        qDebug() << "F released";
    } else if(state->keyE){
        state->keyE = false;
        qDebug() << "E released";
    } else if(state->keyR){
        state->keyR = false;
        qDebug() << "R released";
    }
    state->newCoord[0] = 0;
    state->newCoord[1] = 0;
    state->newCoord[2] = 0;

}

void Viewport::wheelEvent(QWheelEvent *event) {

    if(event->delta() > 0) {
        handleMouseWheelForward(event, viewportType);
    } else {
        handleMouseWheelBackward(event, viewportType);
    }

}

void Viewport::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Control) {
        setCursor(Qt::OpenHandCursor);
    }
    this->delegate->handleKeyboard(event, focus);
    if(event->isAutoRepeat()) {
        event->ignore();
    }

}


void Viewport::drawViewport(int viewportType) {
    reference->renderOrthogonalVP(viewportType);

}

void Viewport::drawSkeletonViewport() {
    reference->renderSkeletonVP(VIEWPORT_SKELETON);
}

bool Viewport::handleMouseButtonLeft(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseButtonLeft(event, VPfound);
}

bool Viewport::handleMouseButtonMiddle(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseButtonMiddle(event, VPfound);

}

bool Viewport::handleMouseButtonRight(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseButtonRight(event, VPfound);
}


bool Viewport::handleMouseMotionLeftHold(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseMotionLeftHold(event, VPfound);
}

bool Viewport::handleMouseMotionMiddleHold(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseMotionMiddleHold(event, VPfound);
}

bool Viewport::handleMouseMotionRightHold(QMouseEvent *event, int VPfound) {
    return delegate->handleMouseMotionRightHold(event, VPfound);
}

bool Viewport::handleMouseWheelForward(QWheelEvent *event, int VPfound) {
    return delegate->handleMouseWheelForward(event, VPfound);
}

bool Viewport::handleMouseWheelBackward(QWheelEvent *event, int VPfound) {
    return delegate->handleMouseWheelBackward(event, VPfound);
}


void Viewport::enterEvent(QEvent *event) {
    entered = true;
    focus = this->viewportType;
    this->setCursor(Qt::CrossCursor);
}
/*
void Viewport::paintEvent(QPaintEvent *event) {

}*/

/*
void Viewport::leaveEvent(QEvent *event) {
    entered = false;    

}
*/

void Viewport::zoomOrthogonals(float step){

    int triggerMagChange = false;

    for(uint i = 0; i < state->viewerState->numberViewports; i++) {
        if(state->viewerState->vpConfigs[i].type != VIEWPORT_SKELETON) {

            /* check if mag is locked */
            if(state->viewerState->datasetMagLock) {
                if(!(state->viewerState->vpConfigs[i].texture.zoomLevel + step < VPZOOMMAX) &&
                   !(state->viewerState->vpConfigs[i].texture.zoomLevel + step > VPZOOMMIN)) {
                    state->viewerState->vpConfigs[i].texture.zoomLevel += step;
                }
            }
            else {
                /* trigger a mag change when possible */
                if((state->viewerState->vpConfigs[i].texture.zoomLevel + step < 0.5)
                    && (state->viewerState->vpConfigs[i].texture.zoomLevel >= 0.5)
                    && (state->magnification != state->lowestAvailableMag)) {
                    state->viewerState->vpConfigs[i].texture.zoomLevel += step;
                    triggerMagChange = MAG_DOWN;
                }
                if((state->viewerState->vpConfigs[i].texture.zoomLevel + step > 1.0)
                    && (state->viewerState->vpConfigs[i].texture.zoomLevel <= 1.0)
                    && (state->magnification != state->highestAvailableMag)) {
                    state->viewerState->vpConfigs[i].texture.zoomLevel += step;
                    triggerMagChange = MAG_UP;
                }
                /* performe normal zooming otherwise. This case also covers
                * the special case of zooming in further than 0.5 on mag1 */
                if(!triggerMagChange) {
                    if(!(state->viewerState->vpConfigs[i].texture.zoomLevel + step < 0.09999) &&
                       !(state->viewerState->vpConfigs[i].texture.zoomLevel + step > 1.0000)) {
                        state->viewerState->vpConfigs[i].texture.zoomLevel += step;
                    }
                }
            }
        }
    }

   if(triggerMagChange)
        emit changeDatasetMagSignal(triggerMagChange);

   emit recalcTextureOffsetsSignal();

}

void Viewport::resizeVP(QMouseEvent *event) {
    if(event->x() >= event->y()) {
        resize(event->x(), event->x());
    }
    else {
        resize(event->y(), event->y());
    }
    if(height() < 50) {
        resize(50, 50);
    }
    else if(height() > parentWidget()->height() - 60) {
        resize(parentWidget()->height() - 60, parentWidget()->height() - 60);
    }
    if(width() < 50) {
        resize(50, 50);
    }
    else if(width() > parentWidget()->width()) {
        resize(parentWidget()->width(), parentWidget()->width());
    }
    resizeButton->setGeometry(width() - ResizeButton::SIZE, height() - ResizeButton::SIZE, ResizeButton::SIZE, ResizeButton::SIZE);
}

void Viewport::moveVP(QMouseEvent *event) {
    raise();
    int x = pos().x() + xrel(event->x());
    int y = pos().y() + yrel(event->y());
    if(x >= 0 && x <= (parentWidget()->width() - width())
       && y >= 0 && y <= (parentWidget()->height() - height())) {
        move(x, y);
    }
    else if(x >= 0 && x <= (parentWidget()->width() - width())) {
        move(x, pos().y());
    }
    else if(y >= 0 && y <= (parentWidget()->height() - height())) {
        move(pos().x(), y);
    }
}

void Viewport::moveButtonClicked() {

}

void Viewport::resizeButtonClicked() {
    resizeButtonHold = true;
    raise();
}

void Viewport::xyButtonClicked() {

}

void Viewport::xzButtonClicked() {

}

void Viewport::yzButtonClicked() {

}

void Viewport::r90ButtonClicked() {

}

void Viewport::r180ButtonClicked() {

}

void Viewport::resetButtonClicked() {

}
