#pragma once

namespace al {
    class FunctorBase {
    public:
        FunctorBase() = default;
        FunctorBase(const FunctorBase& copy) = default;
        virtual void operator()() const = 0;
        virtual FunctorBase* clone() const = 0;

        virtual ~FunctorBase() {}
    };

    template <class T, class F>
    class FunctorV0M : public FunctorBase {
    public:
        FunctorV0M() = default;

        FunctorV0M(T objPointer, F functPointer) : mObjPointer(objPointer), mFunctPointer(functPointer) {}

        FunctorV0M(const FunctorV0M& copy) = default;

        void operator()() const override { (mObjPointer->*mFunctPointer)(); }

        FunctorV0M* clone() const override { return new FunctorV0M(*this); }

    private:
        T mObjPointer = nullptr;
        F mFunctPointer = nullptr;
    };

}
