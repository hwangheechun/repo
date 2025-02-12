﻿#pragma once
class D2DRenderer final 
{
public:
	static D2DRenderer* GetInstance()
	{
		static D2DRenderer instance;
		return &instance;
	}

private:
	D2DRenderer();
	virtual ~D2DRenderer();
public:
	enum class DefaultBrush : UINT
	{
		White = 0, Black, Yellow, Red, Blue, Green, Gray, End
	};
private:
	typedef map<wstring, IDWriteTextFormat*>::iterator TextIter;
private:
	ID2D1Factory* _D2DFactory;
	ID2D1HwndRenderTarget* _D2DRenderTarget;
	IDXGISurface* _D2DSurface;

	IDWriteFactory* _DWFactory;

	ID2D1SolidColorBrush* _defaultBrushList[((UINT)DefaultBrush::End)];
	map<wstring, IDWriteTextFormat*> _fontList;
public:
	void BeginRender(const D2D1::ColorF& backgroundColor);
	void EndRender();
private:
	void CreateFactory();
	void CreateRenderTarget();
	void CreateDefaultBrush();
public:
	void AddTextFormat(const wstring& font, const float& defaultSize = 1.f);
	inline ID2D1RenderTarget* const GetRenderTarget()const { return this->_D2DRenderTarget; }
public:
	//텍스트 출력 (기본 브러쉬 사용) 
	void RenderText(const int x, const int y, const wstring& text, const int size,
		const DefaultBrush& defaultBrush = DefaultBrush::Black,
		const DWRITE_TEXT_ALIGNMENT& align = DWRITE_TEXT_ALIGNMENT_LEADING, 
		const wstring& font = L"맑은고딕");
	//텍스트 출력 (원하는 색상과 알파값으로 브러쉬 생성해서 출력)
	void RenderText(const int x, const int y, const wstring& text, const COLORREF& color, const float alpha, const int size,
		const DWRITE_TEXT_ALIGNMENT& align = DWRITE_TEXT_ALIGNMENT_LEADING, 
		const wstring& font = L"맑은고딕");
	//텍스트 필드 출력 (기본 브러쉬 사용) 
	void RenderTextField(const int x, const int y, const wstring& text, const int size, const int width, const int height,
		const DefaultBrush& defaultBrush = DefaultBrush::Black,
		const DWRITE_TEXT_ALIGNMENT& align = DWRITE_TEXT_ALIGNMENT_LEADING, 
		const wstring& font = L"맑은고딕");
	//텍스트 필드 출력 (원하는 색상과 알파값으로 브러쉬 생성해서 출력)
	void RenderTextField(const int x, const int y, const wstring& text, const COLORREF& color,
		const int size, const int width, const int height,
		const float alpha = 1.0f,
		const DWRITE_TEXT_ALIGNMENT& align = DWRITE_TEXT_ALIGNMENT_LEADING,
		const wstring& font = L"맑은고딕");

	void DrawLine(const Vector2& start, const Vector2& end, const D2D1::ColorF::Enum& color, const float alpha, const float strokeWidth = 1.f);
	void DrawLine(const Vector2& start, const Vector2& end, const DefaultBrush& defaultBrush = DefaultBrush::Black, const float strokeWidth = 1.f);

	void DrawRectangle(const FloatRect& rc, const D2D1::ColorF::Enum& color, const float alpha, const float strokeWidth = 1.f);
	void DrawRectangle(const FloatRect& rc, const DefaultBrush& defaultBrush = DefaultBrush::Black, const float strokeWidth = 1.f);

	void DrawEllipse(const Vector2& origin, const float radius, const DefaultBrush& defaultBrush = DefaultBrush::Black, const float strokeWidth = 1.f);
	void DrawEllipse(const Vector2& origin, const float radius, const D2D1::ColorF::Enum& color, const float alpha, const float strokeWidth = 1.f);

	void FillRectangle(const FloatRect& rc, const  D2D1::ColorF::Enum& color, const float alpha);
	void FillRectangle(const FloatRect& rc, const DefaultBrush& defaultBrush = DefaultBrush::Black);

	void FiilEllipse(const Vector2& origin, const float radius, const D2D1::ColorF::Enum& color, const float alpha);
	void FiilEllipse(const Vector2& origin, const float radius, const DefaultBrush& brush = DefaultBrush::Black);

	void DrawRotationNullRectangle(const FloatRect& rc, const D2D1::ColorF::Enum& color, const float alpha, const float angle, const float strokeWidth = 1.f);
	void DrawRotationFillRectangle(const FloatRect& rc, const D2D1::ColorF& color, const float angle);
};

#define _D2DRenderer D2DRenderer::GetInstance()