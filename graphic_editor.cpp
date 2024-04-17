#include <iostream>
using namespace std;


class IGraphicEditor
{
public:
    
    class IShapeDrawing
    {
    public:
        virtual void DrawShape() = 0;
        virtual void MoveShape() = 0;
        virtual void ResizeShape() = 0;
    };

    class IColorEditing
    {
    public:
        virtual void ChooseColor() = 0;
    };

    class ILayerHandling
    {
    public:
        virtual void AddLayer() = 0;
        virtual void RemoveLayer() = 0;
        virtual void MergeLayers() = 0;
    };

    virtual IShapeDrawing* GetShapeDrawingInterface() = 0;
    virtual IColorEditing* GetColorEditingInterface() = 0;
    virtual ILayerHandling* GetLayerHandlingInterface() = 0;
};

class GraphicEditor : public IGraphicEditor
{
public:
   
    IShapeDrawing* GetShapeDrawingInterface() override { return &shapeDrawing; }
    IColorEditing* GetColorEditingInterface() override { return &colorEditing; }
    ILayerHandling* GetLayerHandlingInterface() override { return &layerHandling; }

private:
    class ShapeDrawing : public IShapeDrawing
    {
    public:
        void DrawShape() override {}
        void MoveShape() override {}
        void ResizeShape() override {}
    } shapeDrawing;

    class ColorEditing : public IColorEditing
    {
    public:
        void ChooseColor() override {}
    } colorEditing;

    class LayerHandling : public ILayerHandling
    {
    public:
        void AddLayer() override {}
        void RemoveLayer() override {}
        void MergeLayers() override {}
    } layerHandling;
};