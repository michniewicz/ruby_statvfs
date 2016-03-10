require_relative 'statvfs_lib/statvfs'
##
# Represents StatVFS class as a wrapper for native statvfs function
#
# Example: puts StatVFS.new.info  ## prints hash of file system stats values
#
class StatVFS
  # include Statvfs module
  include Statvfs

  attr_reader :info

  def initialize(path = '/')
    @info = get_statvfs(path)
  end
end
