 void SvgWriter::Clear()
  {
    for (PathInfoList::iterator pi_iter = path_infos.begin();
      pi_iter != path_infos.end(); ++pi_iter) delete (*pi_iter);
    path_infos.resize(0);
  }
  //------------------------------------------------------------------------------

  void SvgWriter::SetCoordsStyle(const std::string &font_name,
      unsigned font_color, unsigned font_size)
  {
    coords_style.font_name = font_name;
    coords_style.font_color = font_color;
    coords_style.font_size = font_size;
  }
  //------------------------------------------------------------------------------

  void SvgWriter::AddText(const std::string &text,
    unsigned font_color, unsigned font_size, double x, double y)
  {
      text_infos.push_back(new TextInfo(text, "", font_color, 600, font_size, x, y));
  }
  //------------------------------------------------------------------------------

  void SvgWriter::AddPath(const Path64& path, bool is_open, FillRule fillrule,
    unsigned brush_color, unsigned pen_color, double pen_width, bool show_coords)
  {
    int error_code = 0;
    if (path.size() == 0) return;
    PathsD tmp;
