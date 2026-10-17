#pragma once

namespace nn::g3d {
    class ShapeObj;
    class ViewVolume;
}

namespace agl {
    class DrawContext;
}

namespace al {
    class ModelShapeCtrl;
}

namespace alModelShapeFunction {
    void drawShape(agl::DrawContext*, const al::ModelShapeCtrl&, const nn::g3d::ViewVolume*, const nn::g3d::ShapeObj&, int, bool);
    void drawShapeCtrl(agl::DrawContext*, const al::ModelShapeCtrl&, const nn::g3d::ViewVolume*, const nn::g3d::ShapeObj&, int, bool);
    void drawShapeCulled(agl::DrawContext*, const al::ModelShapeCtrl&);
}
