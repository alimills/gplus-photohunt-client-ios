//
//  StreamSource.h
//  PhotoHunt

#import <Foundation/Foundation.h>
#import "FSHPhotos.h"
#import "ImageCache.h"
#import "PhotoCardView.h"
#import "TakePhotoView.h"

// Protocol for calling back to the owner for the theme data and status.
@protocol StreamSourceDelegate <NSObject>

// Return YES if the app is in a state that the user can take a photo.
- (BOOL)canTakePhoto;

// Return the photos list for all users.
- (FSHPhotos *)allUserPhotos;

// Return the photos list for photos by friends of the user.
- (FSHPhotos *)friendPhotos;

// Return the current user.
- (FSHProfile *)currentUser;

// Return the current theme.
- (FSHTheme *)currentTheme;

// Return a monotonically increasing counter which is used for cache clearing.
- (NSInteger)counter;

// Return a delegate suitable for use by the photocards.
- (id<PhotoCardViewDelegate,TakePhotoViewDelegate>)cardDelegate;

@end

// Manage the table view that displays the stream.
@interface StreamSource : NSObject <
    UITableViewDataSource,
    UITableViewDelegate> {
}

@property (nonatomic, assign) id<StreamSourceDelegate> delegate;
@property (nonatomic, retain) ImageCache *cache;

// Initialise a new stream manager with the delegate for callbacks and
// an |ImageCache| for use with the individual photocards.
- (id)initWithDelegate:(id<StreamSourceDelegate>)delegate
              useCache:(ImageCache *)cache;

@end
