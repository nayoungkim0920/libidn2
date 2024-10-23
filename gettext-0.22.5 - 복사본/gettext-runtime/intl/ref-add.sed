/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ libintl / libintl /
  tb
  s/ $/ libintl /
  :b
  s/^/# Packages using this file:/
}
