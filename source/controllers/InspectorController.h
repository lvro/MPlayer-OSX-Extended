/*  
 *  InspectorController.h
 *  MPlayer OSX Extended
 *  
 *  Created on 01.01.2010
 *  
 *  Description:
 *	Controller for the inspector pane.
 *  
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */


#import <Cocoa/Cocoa.h>


@interface InspectorController : NSObject {
	
	IBOutlet NSWindow *window;
	
	IBOutlet NSScrollView *scroller;
	IBOutlet NSView *container;
	IBOutlet NSView *fileAttributesSection;
	IBOutlet NSView *playbackSettingsSection;
	IBOutlet NSView *statisticsSection;
	
	IBOutlet NSButton *fileAttributesTriangle;
	IBOutlet NSButton *playbackSettingsTriangle;
	IBOutlet NSButton *statisticsTriangle;
	
	NSDictionary *views;
	NSDictionary *triangles;
	NSMutableDictionary *expandedHeights;
	NSArray *sectionOrder;
	
	BOOL isResizing;
	float lastSectionHeight;
	
	BOOL statsExpanded;
	
	IBOutlet NSSlider *playbackSpeed;
	IBOutlet NSSlider *audioDelay;
	IBOutlet NSSlider *subtitleDelay;
	IBOutlet NSSlider *audioBoost;
	IBOutlet NSSlider *subtitleScale;
}

@property (nonatomic,readonly) NSWindow *window;

- (IBAction)toggleSection:(id)sender;
- (void)sectionDidResize:(NSNotification *)notification;

- (void)positionSections:(id)sender;

- (IBAction)resetPlaybackSpeed:(id)sender;
- (IBAction)resetAudioDelay:(id)sender;
- (IBAction)resetSubtitleDelay:(id)sender;
- (IBAction)resetAudioBoost:(id)sender;
- (IBAction)resetSubtitleScale:(id)sender;

@end

@interface MultiplicatorTransformer100Fold : NSValueTransformer { }
- (float)scale;
@end