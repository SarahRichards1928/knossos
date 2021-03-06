#ifndef LOADER_H
#define LOADER_H

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

#include "segmentation.h"

#include <QObject>
#include <QSemaphore>
#include <QThread>

#include <boost/multi_array.hpp>

#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/* Calculate movement trajectory for loading based on how many last single movements */
#define LL_CURRENT_DIRECTIONS_SIZE (20)
/* Max number of metrics allowed for sorting loading order */
#define LL_METRIC_NUM (20)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
/*
* For the loader ad-hoc linked list
*/
#define LLL_SUCCESS  1
#define LLL_FAILURE  0

#define LM_LOCAL    0
#define LM_FTP      1

#define FTP_RETRY_NUM 3

struct C_Element {
    Coordinate coordinate; // coordinate * cubeEdgeLength = minimal coordinate in the cube; NOT center coordinate

    char *data_filename;
    char *overlay_filename;
    char *path;
    char *fullpath_data_filename;
    char *fullpath_overlay_filename;
    char *local_data_filename;
    char *local_overlay_filename;
    CURL *curlDataHandle;
    CURL *curlOverlayHandle;
    FILE *ftp_data_fh;
    FILE *ftp_overlay_fh;
    bool hasError;
    bool hasDataError;
    bool hasOverlayError;
    int retries;
    bool isFinished;
    bool isDataFinished;
    bool isOverlayFinished;
    bool isAborted;
    int isLoaded;

    //uint debugVal;
    //DWORD tickDownloaded;
    //DWORD tickDecompressed;

    C_Element *previous;
    C_Element *next;
};

class Loader;

struct ftp_thread_struct {
/*
    DWORD debugVal;
    DWORD beginTickCount;
*/
    QSemaphore *ftpThreadSem;
    QSemaphore *loaderThreadSem;
    int cubeCount;
    Loader* thisPtr;
};

struct loadcube_thread_struct {
    //DWORD beginTickCount;
    //DWORD decompTime;
    int threadIndex = 0;
    QSemaphore *loadCubeThreadSem = nullptr;
    int isBusy = 0;
    C_Element *currentCube = nullptr;
    Loader* thisPtr = nullptr;
    bool retVal = false;
    int threadCount = 0;
};

class LoadCubeThread : public QThread
{
public:
    LoadCubeThread(void *ctx);
    void run();
protected:
    void *ctx;
};

struct LO_Element {
        Coordinate coordinate;
        Coordinate offset;
        float loadOrderMetrics[LL_METRIC_NUM];
};

int calc_nonzero_sign(float x);

class Loader : public QThread {
    Q_OBJECT
    friend class LoadCubeThread;
    friend void writeVoxel(const Coordinate &, const uint64_t);
    friend boost::multi_array_ref<uint64_t, 3> getCube(const Coordinate & pos);
    friend void annotationFileLoad(const QString &, const QString &, bool *);
    friend void annotationFileSave(const QString &, bool *);
    friend void Segmentation::clear();
private:
    std::list<std::vector<Byte>> DcSetChunk;
    std::list<std::vector<Byte>> OcSetChunk;
    std::list<Byte*> freeDcSlots;
    std::list<Byte*> freeOcSlots;
    std::unordered_set<CoordOfCube> OcModifiedCacheQueue;
    std::unordered_map<CoordOfCube, std::string> snappyCache;
    Byte *bogusDc;
    Byte *bogusOc;
    bool magChange;
    int currentMaxMetric;
    coord2bytep_map_t mergeCube2Pointer;
    void run();
    bool initLoader();
    bool uninitLoader();
    uint prevLoaderMagnification;
    void CalcLoadOrderMetric(float halfSc, floatCoordinate currentMetricPos, floatCoordinate direction, float *metrics);
    floatCoordinate find_close_xyz(floatCoordinate direction);
    int addCubicDcSet(int xBase, int yBase, int zBase, int edgeLen, C_Element *target, coord2bytep_map_t *currentLoadedHash);
    uint DcoiFromPos(C_Element *Dcoi, coord2bytep_map_t *currentLoadedHash);
    void loadCube(loadcube_thread_struct *lts);
    uint removeLoadedCubes(const coord2bytep_map_t &currentLoadedHash, uint prevLoaderMagnification);
    uint loadCubes();
    void snappyCacheAdd(const CoordOfCube &, const Byte *cube);
    void snappyCacheClear();
    void snappyCacheFlush();
public:
    explicit Loader(QObject *parent = 0);
    int CompareLoadOrderMetric(const void * a, const void * b);

    C_Element *Dcoi;
signals:
    void finished();
    void reslice_notify();
public slots:
    bool load();
};

#endif // LOADER_H
