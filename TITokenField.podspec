Pod::Spec.new do |s|
  s.name     = 'TITokenField'
  s.version  = '1.0.10'
  s.source   = { :git => 'https://github.com/margarina/TITokenField.git' }
  s.authors =  { "Tom Irving" => "info@thermoglobalnuclearwar.com" }
  s.source_files = 'TokenFieldOnly/*'
  s.requires_arc = true
  s.license = 'MIT'
  s.homepage = 'https://github.com/Batterii/TITokenField'
  s.summary = 'An iOS version of the NSTokenField (See To: field in Mail and Messages).'
end
